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

	w = 10;
	h = 20;
	cv = canvas(w,h);
        red = color(1,0,0);
	writePixel(&cv,0,0,red);	
	writePixel(&cv,19,0,red);
       	writePixel(&cv,0,9,red);
	writePixel(&cv,19,9,red);
	resp = canvas_to_ppm(&cv);	
}
