#pragma once

#include <../../SFML-2.5.0/include/SFML/System.hpp>

#include "../../UserSettings/Config.h"

class MovementFOV
{
public:
	MovementFOV(const Config &config);

	void sprint();
	void walk();
private:
	int m_MinFOV;
	int m_MaxFOV;

	sf::Clock m_Clock;
};