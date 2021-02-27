#include "include/header.h"

// int main(int argc, char *argv[])
// {
// 	t_config	config;
// 	t_canvas 	c;
	
// 	c =  canvas(1,1);

// 	c.pixel[0][0].red = 0;
// 	c.pixel[0][0].green = 1;
// 	c.pixel[0][0].blue = 0;

// 	config.R_x = 1;
// 	config.R_y = 1;

// 	ft_printf("File %d filename %s\n", argc, argv[1]);
// 	ft_save(config,c, 001);

// 	return (0);
// }


int main(int argc, char *argv[])
{
	char		*erro;
	int			fd;
	int			ii;
	char    	*line;
	int			tag;
	t_config	config;
	t_world		w;
	t_objects *temp;
	t_lights *temp_l;

	config.c_cameras = NULL;
	config.l_lights = NULL;
	config.o_objects = NULL;
	erro = NULL;
	if (argc < 2)
	{
		erro = ft_error("001");
		ft_printf("%s\n", erro);
		return (0);
	}
	if (argc > 3)
	{
		erro = ft_error("002");
		ft_printf("%s\n", erro);
		return (0);
	}
	if (argc == 3 && ft_memcmp("--save",argv[2],4) != 0)
	{
		erro = ft_error("003");
		ft_printf("%s\n", erro);
		return (0);
	}
	line = NULL;
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		ft_printf("\nError in open\n");
		return (0);
	}

	tag = 0;
	while ((ii = get_next_line(fd, &line)) > 0)
	{	
		if (line != NULL && *line != '\0')
		{

			ft_conf(&config,line,tag);
			free(line);
		}
		tag++;
	}
	tag++;
	if (line != NULL && *line != '\0')
	{
		ft_conf(&config,line,tag);
		free(line);
	}

	w.objects = NULL;
	w.lights = NULL;
	temp = config.o_objects;
	while (temp->next)
	{
		world(&w,temp->content);
		temp = temp->next;
	}
	world(&w,temp->content);

	temp_l = config.l_lights;
	if (temp_l != NULL)
	{
		while (temp_l->next)
		{
			light_a(&w,temp_l->content);
			temp_l = temp_l->next;
		}
		light_a(&w,temp_l->content);
	}


	w.ambient = config.A_color;


	t_canvas canvas;
	t_camera c;
	// char *s;
	int i;
	c = config.c_cameras->content;
	canvas = render(c,w);
	//s = canvas_to_ppm(&canvas);
	ft_save(config,canvas, 001);
	i = 0;
	while (i <c.vsize)
	{
		free(canvas.pixel[i]);
		i++;
	}



	// free(s);
	// ft_lstclear_w(&w.objects);
	// ft_lstclear_l(&w.lights);
	// free(canvas.pixel);
	// freeMatrix(&c.transform);
	// free(w.objects);
	// freeMatrix(&floor.transform);
	// freeMatrix(&left.transform);
	// freeMatrix(&right.transform);
	// freeMatrix(&middle.transform);
	// freeMatrix(&top_left.transform);
	return (0);
}