#include "include/header.h"

int main(int argc, char *argv[])
{
	t_config	config;
	t_world		w;

	if (ft_prevalidation(argc, argv))
	{
		return (0);
	}
	config.save = ft_checkSave(argc);

	ft_readfile(&config,argv);
	ft_init_world(&w,config);
	ft_canvas(&config,w);
	ft_renderCamera(config, config.save);

//void ft_freeCanvas(t_canvas *canvas)
	// int i;
	// i = 0;
	// while (i <c.vsize)
	// {
	// 	free(canvas.pixel[i]);
	// 	i++;
	// }
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
