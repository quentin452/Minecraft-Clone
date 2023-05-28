#include "PostProcessRenderer.h"

#include <iostream>

#include "../Camera.h"
#include "../Maths/Matrix.h"
#include "../RenderSettings.h"
#include "../ShaderData.h"
#include "../GlobalInfo.h"
#include "../Player/PlayerInfo.h"

PostProcessRender::PostProcessRender()
{
	m_quadModel.addData({
		{
			-1, 1, 0,
			1, 1, 0,
			1, -1, 0,
			-1, -1, 0,
		},
		{
			0, 1,
			1, 1,
			1, 0,
			0, 0,
		},
		{
			0, 1, 2,
			2, 3, 0
		}
		});
}

void PostProcessRender::add(const glm::vec3& position)
{
	m_quads.push_back(position);
}

void PostProcessRender::render(const Camera& camera, FrameBufferObject& fbo)
{
	begin();

	// Clear the FBO's color and depth buffers
	fbo.bind();
	fbo.clear();

	if (g_ShaderSettings.motionblur) {
		mblur.render(camera, fbo);
	}

	if (g_ShaderSettings.fxaa) {
		antialias.render(fbo.getColorTex());
	}

	if (g_ShaderSettings.bloom) {
		bloom.render(fbo.getColorTex());
	}

	// Rebind the main framebuffer before rendering the final post-processing result
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	glBindTexture(GL_TEXTURE_2D, fbo.getColorTex()); // Bind final image
	finalize();
	// glEnable(GL_DEPTH_TEST);
}

void PostProcessRender::begin()
{
	//Clear Screen
	glBindFramebuffer(GL_FRAMEBUFFER, 0); //Set to screen
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, g_RenderSettings.resolutionX, g_RenderSettings.resolutionY);

	//Prepare for rendering
	glDisable(GL_DEPTH_TEST);
	m_quadModel.bindVAO(); //Stays bound
}

void PostProcessRender::finalize()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0); //Set to screen
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, g_RenderSettings.resolutionX, g_RenderSettings.resolutionY);
	m_shader.useProgram();

	m_shader.loadGamma(g_Config.gamma);
	m_shader.loadContrast(g_Config.contrast);
	m_shader.loadBrightness(g_Config.brightness);
	m_shader.loadSaturation(g_Config.saturation);
	m_shader.loadValue(g_Config.value);

	m_shader.loadResolution(glm::vec2(g_RenderSettings.resolutionX, g_RenderSettings.resolutionY));
	m_shader.loadUnderwater(g_PlayerInfo.underwater);
	if (g_PlayerInfo.darkScreen)
		m_shader.loadDarkScreen(0.4f); // default value of screen darkness when inventory is opened
	else
		m_shader.loadDarkScreen(1.0f);

	// shaking effect
	glm::mat4 trans = glm::rotate(glm::mat4(1.0f), glm::radians(g_PlayerInfo.cameraRotation), glm::vec3(0.0, 0.0, 1.0));
	trans = glm::scale(trans, glm::vec3(1.01f, 1.01f, 1.0f));
	m_shader.loadModelMatrix(trans);

	GL::drawElements(m_quadModel.getIndicesCount());
}