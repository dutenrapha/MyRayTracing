#include "../include/header.h"

t_ray ray_for_pixel(t_camera camera,float px,float py)
{
	t_ray		r;
	float		xoffset;
	float		yoffset;
	float		world_x;
	float		world_y;
	t_matrix	A;
	t_tuple		pixel;
	t_tuple 	origin;
	t_tuple 	direction;

	xoffset = (px + 0.5) * camera.pixel_size;
	yoffset = (py + 0.5) * camera.pixel_size;

	world_x = camera.half_width - xoffset;
	world_y = camera.half_height - yoffset;
	
	
	A = inverse(camera.transform);
	pixel = matrixMultiVec(A,point(world_x, world_y, -1));
 	origin =  matrixMultiVec(A, point(0, 0, 0));
	freeMatrix(&A);
	direction = normalize(sub(pixel,origin));
	r = ray(origin,direction);
	return (r);
}