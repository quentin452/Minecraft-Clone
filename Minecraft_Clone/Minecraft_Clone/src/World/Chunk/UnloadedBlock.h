#pragma once

#include "../../SFML-2.5.0/include/SFML/System/Vector3.hpp"
#include "../Block/ChunkBlock.h"

struct UnloadedBlock
{
	sf::Vector3i pos;
	ChunkBlock block;

	friend bool operator== (const UnloadedBlock &block1, const UnloadedBlock &block2);
};