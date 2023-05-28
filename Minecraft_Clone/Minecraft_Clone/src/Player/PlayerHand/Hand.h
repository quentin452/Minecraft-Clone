#pragma once

#include "../../SFML-2.5.0/include/SFML/System.hpp"

#include "../PlayerHand/HandMesh.h"
#include "../../World/Block/ChunkBlock.h"
#include "../PlayerHand/HandData.h"

class RenderMaster;
class TextureAtlas;

class Hand
{
public:
	Hand();

	void blockHit();
	void swing();
	void eat();
	void stopEating();
	// returns if hit was made
	bool update(ChunkBlock block);

	void drawHand(RenderMaster & master);

	void leftMouseHold();
	void leftMouseUnhold();
	void rightMouseHold();
	void rightMouseUnhold();
private:
	void makeEmptyHandMesh();
	void makeCubeMesh(ChunkBlock& block);
	void makeCactusMesh(ChunkBlock& block);
	void makeDefaultItemMesh(ChunkBlock& block);

	bool			m_leftMouseHolded;
	bool			m_rightMouseHolded;
	bool			m_soundMade;
	AnimationType	m_animationType;
	sf::Clock		m_animationTimer;
	float			m_animationStage;
	BlockId			m_lastItemInHand;
	AnimationType	m_lastAnimationType;

	TextureAtlas*	m_pTexturAtlas;
	HandMesh		m_handMesh;
};