#include "../include/header.h"

void light(t_lights **l, t_light light)
{
    t_lights *temp;
    if(ft_lstsize_l(*l) == 0)
    {
        *l = ft_lstnew_l(light);
    }
    else
    {
		temp = *l;
		while (temp->next)
		{
			temp = temp->next;
		}
        temp->next = ft_lstnew_l(light);
    }
}
