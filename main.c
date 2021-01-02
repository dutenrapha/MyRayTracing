#include "include/header.h"
#include <stdio.h>

int main(void)
{
	t_tuple		light_position;
	t_tuple		ray_origin;
	t_tuple		pos;
	t_tuple		normal;
	t_tuple		eye;
	t_canvas	canva;
	t_color		cor;
	t_color		light_color;
	t_object	shape;
	t_ray		r;
	t_list          *xs;
	t_intersection	h;
	t_matrix        m;
	t_light		light;
	float		world_x;
 	float           world_y;
 	float           wall_z;
	float		wall_size;
	float		pixel_size;
	float		half;
	int		canvas_pixels;
	int		y;
	int		x;
	char		*s;
	

	light_position = point(-10, 10, -10);
	light_color = color(1,1,1);
	light = point_light(light_position, light_color);
	ray_origin = point(0, 0, -5);
	wall_z = 10;
	wall_size = 7;
	canvas_pixels = 500;
	pixel_size = wall_size/canvas_pixels;
	half = wall_size/2;
	canva = canvas(canvas_pixels, canvas_pixels);
	shape = sphere(1);
	shape.material = material();
	shape.material.color = color(0,0,1);
	//shape.material.color = color(1,0.2,1);
	y = 0;
	while(y < canvas_pixels)
	{
		world_y = half - pixel_size*y;
		x = 0;
		while(x < canvas_pixels)
		{
			world_x = -half + pixel_size*x;			
			pos = point(world_x, world_y, wall_z);
			r = ray(ray_origin, normalize(sub(pos,ray_origin)));
			xs = intersect(shape,r);
			h = hit(xs);
			if(h.valid)
			{
				pos = position(r,h.t);
				normal = normal_at(h.object,pos);
				eye = multi(r.direction,-1);
				cor = lighting(h.object.material,light,pos,eye,normal);
				writePixel(&canva, x, y, cor);	
			}
			ft_lstclear(&xs);
			x++;
		}
		y++;
	}
	
	s = canvas_to_ppm(&canva);	
	
	return (0);
}
