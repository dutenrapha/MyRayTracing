#include "../include/header.h"

t_canvas canvas(int w, int h)
{
	t_canvas c;
	t_color black;
	int i;
	int j;

	i = 0;
	black = color(0,0,0);
	c.width = w;
	c.height = h;
	c.pixel = (t_color**)malloc(sizeof(t_color*) * h);
	while (i < h)
	{
		c.pixel[i] = (t_color *)malloc(sizeof(t_color) * w);
		i++;
	}
	i = 0;
        while (i < h)
        {
			j = 0;
			while (j < w)
			{
				c.pixel[i][j] = black; 
				j++;
			}
			i++;
    	}
	return c;
}
