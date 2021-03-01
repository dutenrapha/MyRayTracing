#include "../include/header.h"

void	ft_canvas(t_config *config,t_world w)
{ 
	t_canvas c;
    t_cameras *camera;

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

