#include "include/header.h"
#include <stdio.h>

int main(void)
{
	t_projectile p;
	t_enviroment e;
	t_canvas cv;
	t_color red;
	char *resp;
	int w; 
	int h;
	int i;
	
	p.position = point(0,1,0);

	p.velocity = multi(normalize(vector(1,1.8,0)), 11.25);

	e.gravity = vector(0,-0.1,0); 
	e.wind = vector(-0.01,0,0);

	w = 450;
	h = 550;
	cv = canvas(w,h);
        red = color(1,0,0);
	i = 120;
	while (p.position.y >= 0)
	{
		printf("(w = $%d, h = %d)\n", h - (int)ceil(p.position.y), i);
		writePixel(&cv, h - (int)ceil(p.position.y), i, red);
		p = tick(e, p);
		i++;
	}
	resp = canvas_to_ppm(&cv);	
}
