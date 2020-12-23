#include "include/header.h"
#include <stdio.h>

int main(void)
{
	t_projectile p;
	t_enviroment e;
	t_canvas cv;
	t_color white;
	t_matrix A;
	t_matrix B;
	t_tuple init;
	t_tuple tmp;
	char *resp;
	int w; 
	int h;
	int i;
	int m;
	
	p.position = point(0,1,0);

	p.velocity = multi(normalize(vector(1,1.8,0)), 11.25);

	e.gravity = vector(0,-0.1,0); 
	e.wind = vector(-0.01,0,0);

	w = 81;
	h = 81;
	m = 40;
	cv = canvas(w,h);
        white = color(1,1,1);
	init = point(0,0,0);
	A = translation(0,0,30);
	init = matrixMultiVec(A, init);
	writePixel(&cv,m + init.x,m + init.z,white);
	i = 1;
	while (i < 12)
	{
		freeMatrix(A);
		A = rotation_y(i* (M_PI/6));
		tmp = matrixMultiVec(A, init);
		writePixel(&cv,m + tmp.x,m + tmp.z,white);
		i++;
	}
	resp = canvas_to_ppm(&cv);	
}
