#include "../include/header.h"

t_camera camera(int hsize,int vsize,float field_of_view)
{
	t_camera	c;
	float		half_view;
	float		aspect;

	c.hsize = hsize;
	c.vsize = vsize;
	c.field_of_view = field_of_view;
	c.transform = identity();
	
	half_view = tan(c.field_of_view / 2);
	aspect =  (float)c.hsize / (float)c.vsize;
	if (aspect >= 1)
	{
		c.half_width = half_view;
 		c.half_height = half_view / aspect;
	}
	else
 	{
		c.half_width = half_view * aspect;
 		c.half_height = half_view;
	}
	c.pixel_size = (c.half_width * 2) / c.hsize;
	return (c);	
}
