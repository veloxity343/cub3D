# <p align='center'>cub3D</p>
*"Right. Nazis dead. Nazi robots dead. Broke all your shit. Helicopters secured."*

## Map Parsing

The ``cub3d`` executable receives the map file to read as a single argument, which must be of ``.cub`` filetype.

The file must follow these rules:
- There must be header lines before the actual map containing the following:
    - At least a line containing ``NO``, ``SO``, ``EA`` and ``WE`` followed by a valid path to an xpm image
    - A line starting with ``F`` (**f**loor) or ``C`` (**c**eiling) followed by a color in RGB separated by commas
- Only `` `` *(empty)*, ``1`` *(wall)*, ``0`` *(floor)*, and either ``N``, ``S``, ``E`` or ``W`` *(Player starting position looking at **N**orth, **S**outh, **E**ast or **W**est)*, will be accepted characters in our map (except if you add other characters as bonus)
- The map may not be rectangular, but it must be surrounded by walls
- Spaces are allowed but the player cannot walk on them, thus every space must also be closed/surrounded by walls
- There must be a single player on the map

## Raycasting

Raycasting is a rendering technique to create a 3D perspective in a 2D map. 
The logic behind RayCasting is to throw rays in the direction of the player view. Basically, we need to check the distance between the player and the nearest wall (i.e. the point where the ray hits a wall) to caculate the height of the vertical lines we draw. Here is a simple depiction of it:

<div align="center">
     <img width="200" alt="Raycast Example 1" src="https://user-images.githubusercontent.com/71781441/154158563-5b4f7641-4f3d-4cca-97f1-4cc79aac16dd.png">
    <img width="233" alt="Raycast Example 2" src="https://user-images.githubusercontent.com/71781441/154159164-667da898-a8d5-4991-a8d0-a6008f111054.png">
</div>

### Walls
    
To calculate the **distance between the player and the nearest wall**, we can use the following algorithm:

**1.** Define and initialize some basic attributes needed for the projection: 

<table align="center">
    <tr aling="center">
        <th> Attribute </th>
        <th> Description </th>
        <th> Value </th>
    </tr>
    <tr align="center">
        <td> FOV </td>
        <td> The field of view of the player
            <div align="center">
    <img width="150" align="center" alt="FOV Image" src="https://user-images.githubusercontent.com/71781441/154864710-baee6726-6f2a-4f37-8125-97a5cf52c4f7.png">
</div>
        <td> 60º </td>
    </tr>
    <tr align="center">
        <td> HFOV </td>
        <td> Half of the player's FOV </td>
        <td> 30º </td>
    </tr>
    <tr align="center">
        <td> Ray angle </td>
        <td> Angle of the player view's direction </td>
        <td> N (270º), S (90º), W (180º), E (0º) </td>
    </tr>
    <tr align="center">
        <td> Ray increment angle </td>
        <td> Angle difference between one ray and the next one </td>
        <td> <code>2 * HFOV / window_width</code> </td>
    </tr>
    <tr align="center">
        <td> Precision </td>
        <td> Size of 'steps' taken every iteration </td>
        <td> 50 </td>
    </tr>
    <tr align="center">
        <td> Limit </td>
        <td> Limit of the distance the player can view </td>
        <td> 11 </td>
    </tr>
    <tr align="center">
        <td> Player's position </td>
        <td> Center of the square where the player is </td>
        <td> <code>(int)(player_x + 0.5), (int)(player_y + 0.5)</code> </td>
    </tr>
</table>


**2.** From the the player's position, we move the ray forward incrementing the x's and y's coordinates of the ray.

<img align="right" width="333" alt="Screenshot 2022-02-20 at 22 35 23" src="https://user-images.githubusercontent.com/71781441/154865310-1b8dc0c5-0def-416f-adb6-7acf2a01c53a.png">

```c
ray.x += ray_cos;
ray.y += ray_sin;
```

where `ray_cos` and `ray_sin` are the following:
```c
ray_cos = cos(degree_to_radians(ray_angle)) / g->ray.precision;
ray_sin = sin(degree_to_radians(ray_angle)) / g->ray.precision;
```

**3.** Repeat step **2** until we reach the limit or we hit a wall.

**4.** Calculate the distance between the player's and the ray's position using the euclidean distance:
```c
distance = sqrt(powf(x - pl.x - 0.5, 2.) + powf(y - pl.y - 0.5, 2.));
```

**5.** Fix fisheye
```c
distance = distance * cos(degree_to_radians(ray_angle - g->ray.angle))
```

This algorith is repeated ``window_width`` times, i.e. in every iteration we increment the angle until we have been through all the field of view. 
This distance is really helpful to calculate the height of the wall height:
```c
wall_height = (window_height / (1.5 * distance));
```

### Textures

Once we have hit a wall and know its position and distance to the player, we must check which side was hit and choose the correct texture for that side of the wall. With the correct texture file and the proper height of the wall at hand it we can read pixels from the texture file at a given width and copy them to the screen, following this formula:

```c
/* Get the color from image i at the given x and y pixel */
color = my_mlx_pixel_get(i, (int)(i->width * (g->x + g->y)) % i->width, z);
```

### Controls

- The ``WASD`` keys move the player up, down, left and right relative to the player's viewing angle
- The ``left`` and ``right`` arrow keys rotate the viewing angle of the player
- Press the ``ESC`` key or the ``X`` button on the window to exit the game

<hr>
<div align="center">
    <img src="https://media.tenor.com/leBT_WccYc0AAAAj/wolfenstein-bj.gif">
</div>
