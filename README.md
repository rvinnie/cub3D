# maze3D (work only on macOS)
My own mini raycaster that draws a 3D maze based on a map.  
Сhanging the map you can change textures, sprites, window size, floor and ceiling color and maze shape.  
## How to use?
1) `make`   
2.1) `./cub3D path_to_map`  
2.2) `./cub3D path_to_map --save` (to save screenshot)   

## Control
Movement - `W A S D`  
Rotate - `← →`

## Example map:
```
R 1260 800

NO ./textures/wall_n.xpm
SO ./textures/wall_s.xpm
WE ./textures/wall_w.xpm
EA ./textures/wall_e.xpm
S ./textures/sprite.xpm
F 167,147,123
C 167,167,171

1111111111111111111111111
1000000000110000000000001
10110000011100E0000000001
100100000000000000000000111111111
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110001
11110111 1110101 101111010001
11111111 1111111 111111111111
```
R - resolution of screen  
NO, SO, WE, EA - paths to textures  
S - path to sprite  
F - floor color in rgb  
F - ceiling color in rgb  

0 - space  
1 - wall  
2 - sprite  
E,W,S,N - direction of the player to one of the cardinal points  
