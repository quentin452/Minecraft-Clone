#pragma once

#include <../../SFML-2.5.0/include/SFML/System.hpp>

class SneakingCamera
{
public:
	SneakingCamera();

	void sneak();
	void stand();
private:
	const float m_maxCamPos;
	const float m_minCamPos;

	sf::Clock m_Clock;
};