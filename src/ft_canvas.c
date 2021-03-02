#include "../include/header.h"

void	ft_canvas(t_config *config,t_world w)
{ 
	t_canvas c;
    t_cameras *camera;

	if (config->c_cameras == NULL)
	{
		c = canvas(config->R_x,config->R_y);
    	cv(&config->c_canvas,c);
	}
	else{
		camera = config->c_cameras;
		while (camera->next)
		{
			c = render(camera->content,w);
			cv(&config->c_canvas,c);
			camera = camera->next;
		}
		c = render(camera->content,w);
		cv(&config->c_canvas,c);
	}
}

