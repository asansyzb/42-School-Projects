# fdf

A simple 3D height-map renderer. You can rotate models, zoom in and out, increase or decrease landschaft, color is defined by relative height in the map.

![alt text](https://github.com/Aliba777/42-School-Projects/blob/master/fdf/screenshot_fdf.png)

### Contents
* [What is fdf?](#what-is-fdf)
* [Why would I use/try it?](#why-would-i-usetry-it)
* [Features](#features)
* [How do I use it?](#how-do-i-use-it)
* [Controls](#controls)

### What is fdf?

[fdf][1] is about creating a simplified 3D graphic representation of arelief landscape.

### Why would I use/try it?

The representation in 3D of a landscape is a critical aspect of modern mapping. For
example, in these times of spatial exploration, to have a 3D representation of Mars is a
prerequisite condition to its conquest. As another example, comparing various 3D representations
of an area of high tectonic activity will allow you to better understand these
phenomenon and their evolution, and as a result be better prepared.

It’s your turn today to modelize in 3D some magnificent landscapes, imaginary or
not...

### Features
  
 	Simple file format definition (array of space-separated integers)
  
 	3D rotations with the arrow keys
  
 	Camera controls (zoom, translate)
  
 	Pretty color gradients!
    
### How do I use it?

Download/clone this repo.

Run `make` in the root folder, an executable called `fdf` should compile directly.

The last command created a `fdf` executable in your directory. Now test it with:


I added **test_maps** folder to test the program on different maps.

	./fdf test_maps/pyramide.fdf

### Controls

	wasd - move the object.
  
  	arrow keys - move the angle.
  
 	+ or -  -  zoom in/out.
  
  	< or > - increase/decrease landshcaft.

Have fun :)

[1]: https://github.com/Aliba777/42-School-Projects/blob/master/fdf/fdf.en.pdf "fdf PDF"
[2]: http://42.us.org "42 USA"
[14]: https://github.com/Aliba777/42-School-Projects/tree/master/libft
