#include "include/header.h"
#include <stdio.h>

int main(void)
{
	t_object	floor;
	t_object	left_wall;
	t_object	right_wall;
	t_object	middle;
	t_object	right;
	t_object	left;
	t_world		w;
	t_matrix	A;
	t_matrix        B;
	t_matrix        C;
	t_camera	c;
	t_canvas	canvas;
	char		*s;
	int			i;
	int			j;

	floor = sphere(1);
	C = scaling(10, 0.01, 10);
	copyMatrix(&floor.transform,C);
	freeMatrix(&C);
	floor.material = material();
	floor.material.color = color(1, 0.9, 0.9);
	floor.material.specular = 0;
	
	left_wall = sphere(2);
	A = translation(0, 0, 5);
	B = rotation_y(-M_PI_4);
	C = matrixMulti(A,B);
	freeMatrix(&A);
	freeMatrix(&B);
	A = rotation_x(M_PI_2);	
	B = matrixMulti(C,A);
	freeMatrix(&A);
    freeMatrix(&C);
	A = scaling(10, 0.01, 10);	
	C = matrixMulti(B,A);
	copyMatrix(&left_wall.transform,C);
	freeMatrix(&A);
	freeMatrix(&B);
    freeMatrix(&C);
	left_wall.material = floor.material;

	right_wall = sphere(3);
	A = translation(0, 0, 5);
	B = rotation_y(M_PI_4);
	C = matrixMulti(A,B);
	freeMatrix(&A);
    freeMatrix(&B);
	A = rotation_x(M_PI_2);
	B = matrixMulti(C,A);
	freeMatrix(&A);
    freeMatrix(&C);
	A = scaling(10, 0.01, 10);
	C = matrixMulti(B,A);
	copyMatrix(&right_wall.transform,C);
	freeMatrix(&A);
	freeMatrix(&C);
	right_wall.material = floor.material;

	middle = sphere(4);
	C = translation(-0.5, 1, 0.5);
	copyMatrix(&middle.transform,C);
	freeMatrix(&C);
	middle.material = material();
	middle.material.color = color(0.1, 1, 0.5);
	middle.material.diffuse = 0.7;
	middle.material.specular = 0.3;

	right = sphere(5);
	A = translation(1.5,0.5,-0.5);
	B = scaling(0.5,0.5,0.5);
	C = matrixMulti(A,B);
	copyMatrix(&right.transform,C);
	freeMatrix(&A);
    freeMatrix(&B);
	freeMatrix(&C);
	right.material = material();
	right.material.color = color(0.5,1,0.1);
	right.material.diffuse = 0.7;
	right.material.specular = 0.3;

	left = sphere(6);
	A = translation(-1.5, 0.33, -0.75);
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

	w = world(6,floor,left_wall,right_wall,middle,right,left); 
	w.light = point_light(point(-10, 10, -10), color(1, 1, 1));	

	c = camera(1000,1000,M_PI/3);
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
	freeMatrix(&left_wall.transform);
	freeMatrix(&right_wall.transform);
	freeMatrix(&right.transform);
	freeMatrix(&left.transform);
	return (0);
}