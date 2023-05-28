#pragma once

#include <../../SFML-2.5.0/include/SFML/Graphics.hpp>
#include "../UserSettings/Config.h"
#include "../Renderer/ChunkRenderer.h"
#include "AimedBlock/DelineateBlockRenderer.h"
#include "AimedBlock/BreakBlockRenderer.h"
#include "../Renderer/FloraRenderer.h"
#include "../Renderer/WaterRenderer.h"
#include "../Renderer/Renderer_2D.h"
#include "../Renderer/DroppedItemsRenderer.h"
#include "../Renderer/HandRenderer.h"

#include "../States/PlayingState.h"
#include "../PostProcess/Framebuffer.h"
#include "../PostProcess/PostProcessRenderer.h"
#include "SFMLRenderer.h"

class Camera;
class ChunkSection;
class ItemIconsMesh;

class RenderMaster {
public:
	RenderMaster();

	void drawSFML(const sf::Drawable &drawable);
	void drawSFMLOverInterface(const sf::Drawable &drawable);
    void addChunkToRender(const ChunkSection &chunk);
	void drawIcons(const IconsMesh &iconsMesh);
	void drawDroppedItems(const DroppedItemsMesh &droppedItemsMesh);
	void drawBreakingBlock();
	void drawHand(const HandMesh & handMesh);

    void finishRender(sf::RenderWindow &window, const Camera &camera);

private:
	PostProcessRender	m_postRenderer;

    ChunkRenderer		m_chunkRenderer;
	BreakBlockRenderer	m_breakBlockRenderer;
	DelineateBlockRenderer	m_delineateBlockRenderer;
    WaterRenderer		m_waterRenderer;
    FloraRenderer		m_floraRenderer;

	DroppedItemsRenderer	m_droppedItemsRenderer;
	HandRenderer		m_handRenderer;

    SFMLRenderer		m_sfmlRenderer;
	Renderer_2D			m_2D_Renderer;

	FrameBufferObject	m_fbo;
};