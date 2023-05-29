# Minecraft-Clone

Developed using C++, OpenGL, SFML, libnoise.<br/>
OpenGL 3.3 or later is required.<br/>
All textures, music and sound belong to the creators of Minecraft.<br/>
The game is compiled in 64 bits<br/>

## The game:
https://github.com/Aidanhouk/Minecraft-Clone/releases/tag/v1.0
https://drive.google.com/file/d/1JKHZTW7CWTI9DH2XYHRX3kWUecQYvA31/view?usp=sharing

## Video:
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

## Features todo :

- Add Entities in game + Player + Mob spawner + Fall blocks [#1](https://github.com/quentin452/Minecraft-Clone/issues/1)   
- Add a save game system [#2](https://github.com/quentin452/Minecraft-Clone/issues/2)
- Add discord RPC [#3](https://github.com/quentin452/Minecraft-Clone/issues/3)   
- Add Hud for settings [#4](https://github.com/quentin452/Minecraft-Clone/issues/4) 
- Add Main Menu [#5](https://github.com/quentin452/Minecraft-Clone/issues/5)
- Add A TPS + FPS graph profiler [#6](https://github.com/quentin452/Minecraft-Clone/issues/6)  
- Add a Creative Menu to Show all blocks in the game [#7](https://github.com/quentin452/Minecraft-Clone/issues/7)  
- Add a Chat features [#8](https://github.com/quentin452/Minecraft-Clone/issues/8)     
- Add F2 + F1 + F5 + F11 Features [#18](https://github.com/quentin452/Minecraft-Clone/issues/18)     
- Add pick block button (middle click) in creative mod [#20](https://github.com/quentin452/Minecraft-Clone/issues/20) 
- Add Command features such as tp position [#21](https://github.com/quentin452/Minecraft-Clone/issues/21)
- Add Particle system [#22](https://github.com/quentin452/Minecraft-Clone/issues/22)     
- Add potion system [#23](https://github.com/quentin452/Minecraft-Clone/issues/23)   
- Add enchantment system [#24](https://github.com/quentin452/Minecraft-Clone/issues/24)
- Add dimension system [#25](https://github.com/quentin452/Minecraft-Clone/issues/25)

## Fix Todo : 

- Fix sneak is not work as intended [#11](https://github.com/quentin452/Minecraft-Clone/issues/11)
- Fix water isn't updated [#12](https://github.com/quentin452/Minecraft-Clone/issues/12)
- Fix can pose sugar cane block without any water [#13](https://github.com/quentin452/Minecraft-Clone/issues/13)
- Fix firsts hits on player are doesn't work [#14](https://github.com/quentin452/Minecraft-Clone/issues/14)
- Fix white Leaves glitch issue when watch leaves above it [#16](https://github.com/quentin452/Minecraft-Clone/issues/16)
- Fix biome Blend is weird [#17](https://github.com/quentin452/Minecraft-Clone/issues/17)
- Fix can walk on the water when press space bar in continue
- Fix texture of glowstonedust
- Fix when left click with apple (eating) i got duplicate animation
- Fix Tooltip aren't stocked because , when i drop and regive the tool into the inventory , he reset the tool durability
- Fix when i click outside the inventory with a tool with durability 130/131 by example i got a second durability bar
- Fix when try to add a precraft like stick + crafting table , only one of this craft is gived(the issue only appear when make an shift click) + when left clicking with an item into the crafted slot , the item disappear

- Fix animation bug when change inventory slot 

## Other todo :  

- Deduplicate some codes
- Make sure when i click on the Middle Click in Creative mode then give the Block in The Inventory
- Make sure to change all minecraft sounds/textures from minecraft to uncopyrighted things
- Make cactus , make hit on the player without needing to move on it
- Make sure that the Dirt Color change in function of biome and not in function of BlockId
- Make check to don't spawn TallGrass if no block are underneath 
- Make Creative mod have infinite block
- Upgrade inventory mouse processing functionality 

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
