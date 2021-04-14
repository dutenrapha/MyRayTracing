#include "../include/header.h"

t_list  *intersect_world(t_world w, t_ray r)
{
	t_list	*xs;
    t_list *init;
    t_objects	*temp;

    xs = NULL;
    init = NULL;
    temp = w.objects;
    while(temp->next)
	{
        init = intersect(temp->content,r);
        if (init != NULL)
        {
            if (xs == NULL)
            {
                xs = init;
            }
            else
            {
                ft_lstadd_back(&xs, init);
            }
        }
        temp = temp->next;
    }
    init = intersect(temp->content,r);
    if (init != NULL)
    {
        if (xs == NULL)
        {
            xs = init;
        }
        else
        {
            ft_lstadd_back(&xs, init);
        }
    }
    bubblesort(&xs);
	return (xs);
}
