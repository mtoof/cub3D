Please don't copy the code if you are trying to do the 42 school project.

The goal of ``cub3d`` is to make a small playable game using raycasting (like [Wolfenstein 3D](https://fr.wikipedia.org/wiki/Wolfenstein_3D)).
https://github.com/kieubo90/cub3D/assets/88286643/4342f75d-facf-4dd6-a30e-ff9f485b26d4

## Subject request
The subject asked us to make a small playable game. It has mandatory and Bonus part. We have decided to include the Bonus part in mandatory part in this repository.
The player must be able to move and the rendering must be smooth.
For the Bonus you should handle Wall collisions, a minimap system, doors which can open and close, animated sprite and rotate the point of view with the mouse.

I believe this project has several challenges

1. Finding the right way to extract the cub information, How to do it?
	1. Read the first 6 lines and check for data validity.
	2. Continue with reading the rest of the .cub file and keep it in a data structure.
1. Map validity, How to do it?
	1. Be aware of spaces. the space can't be inside the map, the space must be srounded by walls or use the space for connection between 1 and the map must be srounded by walls.
	1. The map itselt composed of only 6 charachters 'W' 'S' 'E' 'N' '0' '1'.
	1. You might need to read about floodfill algorithm to check for 3 things:
    - Is the map srounded by wall?
    - Is the player or '0' exist outside of the map?
    - Is there any '0' or player exposed to space?
1. Using and understanding the minilibx drawing tool.
1. Understanding raycasting and the DDA algorithm.


## External resources

+ [Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)
+ [Bresenham's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)
+ [Flood fill algorithm](https://en.wikipedia.org/wiki/Flood_fill)
+ [MiniLibX documentation by Gontjarow](https://gontjarow.github.io/MiniLibX/)
+ [MiniLibX documentation by Harm Smits](https://harm-smits.github.io/42docs/)
+ [42docs](https://harm-smits.github.io/42docs/projects/cub3d)
