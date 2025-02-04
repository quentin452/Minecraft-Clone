#include "DelineateBlockRenderer.h"

#include "../../Camera.h"
#include "../../Player/PlayerInfo.h"

#include <iostream>

DelineateBlockRenderer::DelineateBlockRenderer()
{
	std::vector<GLfloat> vertexCoords{
		-0.005f,  1.005f, -0.005f,
		 1.005f,  1.005f, -0.005f,
		 1.005f,  1.005f,  1.005f,
		-0.005f,  1.005f,  1.005f,
			 
		-0.005f, -0.005f, -0.005f,
		 1.005f, -0.005f, -0.005f,
		 1.005f, -0.005f,  1.005f,
		-0.005f, -0.005f,  1.005f,
	};
	std::vector<GLuint> indexCoords{
		0, 1,
		1, 2,
		2, 3,
		3, 0,

		4, 5,
		5, 6,
		6, 7,
		7, 4,

		0, 4,
		1, 5,
		2, 6,
		3, 7,
	};

	m_model.addDataNoTexture({ vertexCoords, std::vector<GLfloat>(), indexCoords });
}

void DelineateBlockRenderer::render(const Camera &camera)
{
	if (g_PlayerInfo.delineatedBlock.x == 0
		&& g_PlayerInfo.delineatedBlock.y == -1
		&& g_PlayerInfo.delineatedBlock.z == 0)
	{
		return;
	}

	m_delineateShader.useProgram();
	m_model.bindVAO();

	m_delineateShader.loadProjectionViewMatrix(camera.getProjectionViewMatrix());
	m_delineateShader.loadModelMatrix(glm::translate(glm::mat4(1.0f),
		glm::vec3(g_PlayerInfo.delineatedBlock.x, g_PlayerInfo.delineatedBlock.y, g_PlayerInfo.delineatedBlock.z)));
	GL::drawLines(m_model.getIndicesCount());
}