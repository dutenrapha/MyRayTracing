#include "include/header.h"
#include <stdio.h>

int main(void)
{
	t_projectile p;
	t_enviroment e;

	p.position = point(0,1,0);

	p.velocity = normalize(vector(1,1,0));

	e.gravity = vector(0,-0.1,0); 
	e.wind = vector(-0.01,0,0);

	while (p.position.y >= 0)
	{
		printf("A posicao atual de y e %f.\n", p.position.y);
		p = tick(e, p);
	}
}
