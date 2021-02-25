#include "../include/header.h"

void light_a(t_world *w, t_light light)
{
    t_lights *temp;
    w->has_light = true;
    if(ft_lstsize_l(w->lights) == 0)
    {
        w->lights = ft_lstnew_l(light);
    }
    else
    {
		temp = w->lights;
		while (temp->next)
		{
			temp = temp->next;
		}
        temp->next = ft_lstnew_l(light);
    }
}
