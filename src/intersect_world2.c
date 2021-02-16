#include "../include/header.h"

t_list  *intersect_world2(t_world w, t_ray r)
{
	t_list	*xs;
    t_list *init;
    int i;

    i = 0;
    xs = NULL;
    init = NULL;
    while(i < w.num_objects)
	{
        init = intersect2(w.objects[i],r);
        if (init != NULL)
        {
            ft_lstadd_back(&xs, init);
            ft_lstclear(&init);
        }
        i++;
    }
    bubbleSort2(xs);
	return (xs);
}
