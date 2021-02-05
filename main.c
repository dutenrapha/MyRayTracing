#include "include/header.h"
#include <stdio.h>

int main(void)
{
	t_object	floor;
	t_object	middle;
	t_object	right;
	t_object	left;
	t_object	top_left;
	t_world		w;
	t_matrix	A;
	t_matrix        B;
	t_matrix        C;
	t_camera	c;
	t_canvas	canvas;
	char		*s;
	int			i;
	int			j;

	floor = plan(1);
	C = scaling(10, 0.01, 10);
	copyMatrix(&floor.transform,C);
	freeMatrix(&C);
	floor.material = material();
	floor.material.color = color(1, 0.9, 0.9);
	floor.material.specular = 0;

	top_left = triangle(2,point(0, 2, 0), point(-1, 1, 0), point(1, 1, 0));
	C = translation(-2,2,0);
	copyMatrix(&top_left.transform,C);
	freeMatrix(&C);
	top_left.material = material();
	top_left.material.color = color(1, 0.2, 1);


	left = cube(3);
	A = translation(-2.5, 0.33, -0.75);
	B = scaling(0.33,0.33,0.33);
	C = matrixMulti(A,B);
	copyMatrix(&left.transform,C);
	freeMatrix(&A);
	freeMatrix(&B);
	freeMatrix(&C);
	left.material = material();
	left.material.color = color(1,0.8,0.1);
	left.material.diffuse = 0.7;
	left.material.specular = 0.3;

	middle = sphere(4);
	C = translation(-1, 1, 0.5);
	copyMatrix(&middle.transform,C);
	freeMatrix(&C);
	middle.material = material();
	middle.material.color = color(0.1, 1, 0.5);
	middle.material.diffuse = 0.7;
	middle.material.specular = 0.3;

	right = cylinder(5);
	right.closed = true;
	right.minimum = 1;
	right.maximum = 2;
	A = translation(1.5,0,-2);
	B = rotation_x(M_PI/4);
	C = matrixMulti(A,B);
	copyMatrix(&right.transform,C);
	freeMatrix(&A);
	freeMatrix(&B);
	freeMatrix(&C);
	right.material = material();
	right.material.color = color(0.1, 1, 0.5);
	right.material.diffuse = 0.7;
	right.material.specular = 0.3;

	w = world(5,floor,left,right,middle,top_left);
	//w = world(2,floor,top_left);
	w.light = point_light(point(-10, 10, -10), color(1, 1, 1));	

	c = camera(100,100,M_PI/2.5);
	C = view_transform(point(0,1.5,-5),point(0,1,0),vector(0,1,0));
	copyMatrix(&c.transform,C);
	freeMatrix(&C);
	canvas = render(c,w);
	
	s = canvas_to_ppm(&canvas);
	i = 0;
	while (i <c.vsize)
	{
		free(canvas.pixel[i]);
		i++;
	}
	free(canvas.pixel);
	free(s);
	freeMatrix(&c.transform);
	free(w.objects);
	freeMatrix(&floor.transform);
	freeMatrix(&left.transform);
	freeMatrix(&right.transform);
	freeMatrix(&middle.transform);
	freeMatrix(&top_left.transform);
	return (0);
}