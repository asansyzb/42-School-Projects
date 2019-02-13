# wolf3d

![wolf3d screenshot](https://github.com/Aliba777/42-School-Projects/blob/master/wolf3d/screenshot_wolf3d.png)

A [Wolfeinstein-like][1] renderer made in C using minilibX, with textures, basic
lighting and basic map files.

## Compiling
Run `make` and you're set. Runs on Mac OS X.

## Running
Run `./wolf3d [map_file]`, a window should appear. You can navigate through the
map using the arrow keys. Exit by closing the window or pressing ESC.

## Map file format
It's a very simple format. Open a file in your favorite text editor, make sure
you have a grid of integers (each one being it's block ID), and it should work
right out of the box. Spawns at the center of the map.

```
1 1 1 1 1
1 0 2 0 1
1 0 0 0 1
1 1 1 1 1
```
[1]: https://github.com/Aliba777/42-School-Projects/blob/master/wolf3d/wolf3d.en.pdf
