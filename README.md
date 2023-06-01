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

#1     Add main menu
#2     Add settings menu
#2     Add game save system (for chunks)**using LevelDB**
#3     Add entity system in the game + Player + Monster spawner + Falling blocks**using ENTT LIB x64(already installed)**(only 1 per functionnality like 1 Zombie, 1 sand etc...)
#4     Add TPS + FPS profiler with graphical representation when clicking on F6 **using Dear ImGui**
#5     Add creative menu to display all blocks in the game
#6     Add chat features + commands such as tp position
#7     Add F2 + F1 + F5 + F11 key functionality (similar to Minecraft)
#8     Add dimensions(like the nether dimension), water , lava. Leaf decay, cactus and sugar cane growing.(only 1 per functionnality like 1 particle effect , 1 enchantment etc......)
#9     Add enchantments system
#10    Add particle system, potions(can be eated by player), 

## Fixes to be implemented:

#1     Fix crash when going to Z 150, the bug appear because X Y Z cannot be negative , but i want negative value permissive
#2     Fix issue with sneaking not working as intended. **the issue appear when you enable caps lock in rivaturner or vsync** (caused by sneakyFallCheck from Player class)
#3     Fix the ability to place a sugar cane block without water nearby (I want the sugar cane to require water to be planted)
#4     Fix the issue of white leaf flickering (for distant leaves) when looking at leaves above
#5     Fix inconsistency biome blending [#17](https://github.com/quentin452/Minecraft-Clone/issues/17)
#6     Fix animation duplication issue when eating an apple
#7     Fix the issue of tooltips not being saved when depositing and retrieving tools in the inventory, resulting in durability reset + can reset durability when using right keybind in inventory with a tool dragged
#8     Fix the appearance of a second durability bar when clicking outside the inventory with a tool with durability of 130/131, for example **the issue probably appear in the updateInventoryText method from InventoryInterfaceUpdate class** 
#9     Fix the issue with pre-crafting. Currently, when a player tries to create a pre-craft by combining a stick and a crafting table, only one of these crafts is given. This problem occurs only when performing a shift-click. Additionally + when clicking with an item in the crafting slot, the item disappears.
#10    Fix tooltip duplication bug (the duplication occurs at the old item location and appears for less than a second) when changing the item slot **the issue probably appear in the updateInventoryText method from InventoryInterfaceUpdate class**  
#11    Fix significant lag when pressing C to reload chunks (this feature is currently disabled, so it needs to be reactivated in the code)
#12    Fix the ability to walk on water by continuously pressing the space bar

## Other tasks to be completed:

#1     Allow infinite blocks in creative mode
#2     Ensure that I can exit the death menu to respawn, as currently, I remain stuck in the menu and have to restart the game
#3     Ensure that when I click with the middle mouse button in creative mode, the block is added to the inventory
#4     Allow cactus to damage the player without needing to walk on it every time to get damage
#5     Verify that no tall grass blocks generate if there are no blocks underneath
#6     Improve the functionality of the cursor in the inventory (similar to Minecraft for crafting, etc.)
#7     Ensure that the color of the dirt changes based on the biome and not the block ID

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
