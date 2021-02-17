#include "../include/header.h"

t_intersection hit2(t_list *xs)
{
	t_intersection	it;
	int i;
    int lenght;
	t_list *temp;

	i = 0;
	temp = xs;
    lenght = ft_lstsize(xs);
	it.valid = false;
	bubbleSort2(&xs);
	while (i < lenght)
	{
        if (temp->content.t > 0)
        {
            it.t = temp->content.t ;
			it.object = temp->content.object;
			it.valid = true;
			break;
        }
		temp = temp->next;
		i++;
	}
	return (it);
}
