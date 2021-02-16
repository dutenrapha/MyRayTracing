#include "../include/header.h"

t_intersection hit2(t_list *xs)
{
	t_intersection	it;
	int i;
    int lenght;

	i = 0;
    lenght = ft_lstsize(xs);
	it.valid = false;
	bubbleSort2(xs);
	while (i < lenght)
	{
        if (xs->content->t > 0)
        {
            it.t = xs->content->t ;
			it.object = xs->content->object;
			it.valid = true;
			break;
        }
		i++;
	}
	return (it);
}
