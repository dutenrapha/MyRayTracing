#include "include/header.h"

int main(int argc, char *argv[])
{




	t_config	config;
	t_world		w;




//void ft_prevalidation(int argc, char *argv[])
	char		*erro;
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
//void ft_prevalidation(int argc, char *argv[])//

//bool ft_checkSave(int argc, char *argv[])
//config.save = ft_checkSave(int argc, char *argv[])
//bool ft_checkSave(int argc, char *argv[])//

//void ft_readfile(t_config *c);
	int			fd;
	int			ii;
	int			tag;
	char    	*line;
	config.c_cameras = NULL;
	config.l_lights = NULL;
	config.o_objects = NULL;
	config.c_canvas = NULL;
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

//void ft_readfile(t_config *c);//

//ft_init_world(t_world *w, t_config c);
	t_objects *temp;
	t_lights *temp_l;
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
//ft_init_world(t_world *w, t_config c);//

//ft_canvas(t_canvas *canvas);
	t_canvas canvas;
	t_camera c;


	c = config.c_cameras->content;
	canvas = render(c,w);
//ft_canvas(t_canvas *canvas)//


//void ft_renderCamera(t_canvas *canvas, bool save)
	int		x;
	int		y;


    void    *mlx;
    void    *mlx_win;
    t_data  img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, config.R_x, config.R_y, "Hello world!");
    img.img = mlx_new_image(mlx, config.R_x, config.R_y);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);

	t_color cor;
	int R;
	int G;
	int B;
	y = 0;
	while (y < c.vsize - 1)
	{
		x = 0;
		while (x < c.hsize - 1)
		{
			cor = canvas.pixel[y][x];
			R = ft_resizeColor(cor.red);
			G = ft_resizeColor(cor.green);
			B = ft_resizeColor(cor.blue);
			my_mlx_pixel_put(&img, x, y, createRGB(R,G,B));
			x++;
		}
		y++;
	}
    
	// if (save)
	//{
	//ft_save(config,img, 42);
	//}
	//else
	//{
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
	//}
//void ft_renderCamera(t_canvas *canvas)//




//void ft_freeCanvas(t_canvas *canvas)
	int i;
	i = 0;
	while (i <c.vsize)
	{
		free(canvas.pixel[i]);
		i++;
	}
//void ft_freeCanvas(t_canvas *canvas)//


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
