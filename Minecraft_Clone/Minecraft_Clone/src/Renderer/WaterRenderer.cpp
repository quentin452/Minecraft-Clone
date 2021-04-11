#include "WaterRenderer.h"

#include "../Application.h"
#include "../Camera.h"
#include "../World/Block/BlockDatabase.h"
#include "../World/Chunk/ChunkMesh.h"

void WaterRenderer::add(const ChunkMesh &mesh)
{
    m_chunks.push_back(&mesh.getModel().getRenderInfo());
}

void WaterRenderer::render(const Camera &camera)
{
    if (m_chunks.empty()) {
        return;
    }

    glEnable(GL_BLEND);
	glDisable(GL_CULL_FACE);

    m_shader.useProgram();

	m_shader.loadProjectionViewMatrix(camera.getProjectionViewMatrix());
	m_shader.loadProjectionMatrix(camera.getProjMatrix());
	m_shader.loadViewMatrix(camera.getViewMatrix());
	m_shader.loadTime(g_info.elapsedTime);
	m_shader.loadDTime(g_info.dayTime);

	m_shader.loadLighting(g_info.lighting);

    for (auto mesh : m_chunks) {
        GL::bindVAO(mesh->vao);
        GL::drawElements(mesh->indicesCount);
    }

    m_chunks.clear();
}