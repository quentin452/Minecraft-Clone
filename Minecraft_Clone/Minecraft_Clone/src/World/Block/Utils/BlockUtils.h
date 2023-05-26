#include "../BlockId.h"
#include "../World/World/world.h"
#include "Util/Random.h"

using Rand = Random<std::minstd_rand>;

class BlockUtils
{
public:
    BlockUtils() = delete;

public:
    // FIXME TODO DOESN4T WORK 
    bool hasAdjacentWater(World& world, int x, int y, int z);
    // FIXME TODO DOESN4T WORK 
    bool canPlaceSugarcane(BlockId blockId, World& world, int x, int y, int z);
    static bool canPlaceOnBlock(BlockId blockId, BlockId placeOnThisBlockId);

    static BlockId getRandomFlower(Rand& rand);
    static BlockId getRandomDoubleFlower(Rand& rand);
    static BlockId getDoublePlantMain(BlockId blockId);
    static BlockId getDoublePlantSecondPart(BlockId blockId);

public:
    static bool isLiquid(BlockId blockId);

    static bool isDoublePlant(BlockId blockId);

    static bool isWoodPlanks(BlockId blockId);

    static bool isSword(BlockId blockId);
    static bool isPickaxe(BlockId blockId);
    static bool isShovel(BlockId blockId);
    static bool isAxe(BlockId blockId);

    static bool canPickaxeMine(BlockId toolId, BlockId blockId);
};
