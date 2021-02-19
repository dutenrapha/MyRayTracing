#include "include/header.h"

int main(void)
{

	// if (argc < 2)
	// {
	// 	ft_error("001");
	// }
	// if (argc > 3)
	// {
	// 	ft_error("002");
	// }
	// if (argc == 3 && ft_strncmp(argv[2], "--save", 7) != 0)
	// {
	// 	ft_error("003");
	// }
	int test;
	int             fd;
	int				ii;
	char    		*line;

	line = NULL;
	test = ft_printf("%s\n","Hello World");
	if (!(fd = open("minimalist.rt", O_RDONLY)))
	{
		ft_printf("\nError in open\n");
		return (0);
	}
	while ((ii = get_next_line(fd, &line)) > 0)
	{	
		ft_printf("%s\n", line);
	}
	ft_printf("%s\n", line);
	test = ft_printf("%s\n","Hello World");

	t_object	floor;
	t_object	middle;
	t_object	right;
	t_object	left;
	t_object	top_left;
	t_world		w;
	t_world		*p_w;
	t_matrix	A;
	t_matrix        B;
	t_matrix        C;
	t_camera	c;
	t_canvas	canvas;
	char		*s;
	int			i;


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
	middle.material.color = color(0.63, 0.19, 0.57);
	middle.material.diffuse = 0.7;
	middle.material.specular = 0.3;

	right = cylinder(5);
	right.closed = true;
	right.minimum = 1;
	right.maximum = 2;
	A = translation(1.5,0,-2);
	B = rotation_x(M_PI/12);
	C = matrixMulti(A,B);
	copyMatrix(&right.transform,C);
	freeMatrix(&A);
	freeMatrix(&B);
	freeMatrix(&C);
	right.material = material();
	right.material.color = color(0.1, 1, 0.5);
	right.material.diffuse = 0.7;
	right.material.specular = 0.3;

	p_w = &w;
	w.objects = NULL;
	world(p_w,floor);
	world(p_w,left);
	world(p_w,right);
	world(p_w,middle);
	world(p_w,top_left);

	light(&w.lights,point_light(point(-10, 10, -10), color(1, 1, 1)));
	light(&w.lights,point_light(point(10, 10, -10), color(0, 0.1, 0.35)));	
	//light(&w.lights,point_light(point(0, 10, -10), color(0.1, 0.1, 0.1)));


	c = camera(200,200,M_PI/2.5);
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
	ft_lstclear_w(&w.objects);
	ft_lstclear_l(&w.lights);
	free(canvas.pixel);
	free(s);
	freeMatrix(&c.transform);
	free(w.objects);
	freeMatrix(&floor.transform);
	freeMatrix(&left.transform);
	freeMatrix(&right.transform);
	freeMatrix(&middle.transform);
	freeMatrix(&top_left.transform);
	test = ft_printf("%s\n","Bey World");
	return (0);

}