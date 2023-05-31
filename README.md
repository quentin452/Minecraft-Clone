# Minecraft-Clone

Developed using C++, OpenGL, SFML, libnoise.<br/>
OpenGL 3.3 or later is required.<br/>
All textures, music and sound belong to the creators of Minecraft.<br/>
The game is compiled in 64 bits<br/>

## The game:

https://github.com/Aidanhouk/Minecraft-Clone/releases/tag/v1.0
https://drive.google.com/file/d/1JKHZTW7CWTI9DH2XYHRX3kWUecQYvA31/view?usp=sharing

## Video : 

https://youtube.com/playlist?list=PLlqmWU1ThvSpI_KBOWY2OALfcfpfgZbJR

## Implemented features:

- Procedural world generation
- Biomes
- Caves
- Collision detection
- Breaking and placing blocks
- Mining tools with durability
- Items can be dropped
- Inventory
- Crafting
- Sunlight and torchlight
- Ambient occlusion
- Damage, hunger and breathing systems
- Eating
- Creating 3D item meshes out of 2D textures
- Swimming
- Sneaking
- Post processing
- Day & night cycle
- Snow and rain
- Fog
- Surround sound and music!

## Features to be implemented:

    Add entity system in the game + Player + Monster spawner + Falling blocks
    Add game save system (for chunks)
    Add Rich Presence Discord functionality
    Add settings menu, main menu
    Add TPS + FPS profiler with graphical representation
    Add creative menu to display all blocks in the game
    Add chat features + commands such as tp position
    Add F2 + F1 + F5 + F11 key functionality (similar to Minecraft)
    Add particle system, potions, enchantments, dimensions, water, and lava. Leaf decay, cactus and sugar cane growing.

## Fixes to be implemented:

    Fix crash when going to Z 150
    Fix issue with crouching not working as intended. I want to prevent falling from blocks while crouching, similar to Minecraft.
    Fix the ability to place a sugar cane block without water nearby (I want the sugar cane to require water to be planted)
    Fix the issue of white leaf flickering (for distant leaves) when looking at leaves above
    Fix inconsistency biome blending(issue can be founded on my github )
    Fix the ability to walk on water by continuously pressing the space bar
    Fix animation duplication issue when eating an apple
    Fix the issue of tooltips not being saved when depositing and retrieving tools in the inventory, resulting in durability reset
    Fix the appearance of a second durability bar when clicking outside the inventory with a tool with durability of 130/131, for example
    Fix the issue with pre-crafting. Currently, when a player tries to create a pre-craft by combining a stick and a crafting table, only one of these crafts is given. This problem occurs only when performing a shift-click. Additionally, when clicking with an item in the crafting slot, the item disappears.
    Fix tooltip duplication bug (the duplication occurs at the old item location and appears for less than a second) when changing the item slot
    Fix significant lag when pressing C to reload chunks (this feature is currently disabled, so it needs to be reactivated in the code)

## Other tasks to be completed:

    Ensure that I can exit the death menu to respawn, as currently, I remain stuck in the menu and have to restart the game
    Ensure that when I click with the middle mouse button in creative mode, the block is added to the inventory
    Allow cactus to damage the player without needing to walk on it every time to get damage
    Ensure that the color of the dirt changes based on the biome and not the block ID
    Verify that no tall grass blocks generate if there are no blocks underneath
    Allow infinite blocks in creative mode
    Improve the functionality of the cursor in the inventory (similar to Minecraft for crafting, etc.)

## Controls : 

| Button                        | Action                                                         |
|-------------------------------|----------------------------------------------------------------|
| Left mouse button             | Break block                                                    |
| Right mouse button            | Place block                                                    |
| W, A, S, D                    | Move                                                           |
| Space                         | Jump  / swim up  / fly up                                      |
| Left Shift                    | Sneak / swim down/ fly down                                    |
| Hold Ctrl                     | Sprint                                                         |
| Tab                           | Toggle creative mode                                           |
| F                             | Toggle flying (in creative mode)                               |
| E                             | Open/Close inventory                                           |
| Q                             | Drop held item                                                 |
| Mouse wheel                   | Previous/next item in toolbar                                  |
| 0-9                           | Select item in toolbar                                         |
| +/-          			        | Add/subtract 0.5 hour                                          |
| L                             | Lock mouse                                                     |
| P                             | Toggle postprocessing                                          |
| F3                            | Hide/show HUD                                                  |
| F4                            | Toggle fog                                                     |
| F5                            | Turn on weather                                                |
| Esc                           | Pause the game                                                 |
| Enter                         | Unpause the game                                               |
