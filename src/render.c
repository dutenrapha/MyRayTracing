#include "../include/header.h"

t_canvas render(t_camera camera,t_world world)
{
	t_canvas	image;
	int		x;
	int		y;
	t_ray		ray;
	t_color		color;
	char 		a;

	image = canvas(camera.hsize, camera.vsize);
	y = 0;
	while (y < camera.vsize - 1)
	{
		x = 0;
		if (x == 25)
		{
			a = 'a';
		}
		while (x < camera.hsize - 1)
		{
			ray = ray_for_pixel(camera, x, y);
 			color = color_at(world, ray);
 			writePixel(&image, x, y, color);	
			x++;
		}
		y++;
	}
	return (image);
}
