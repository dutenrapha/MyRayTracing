#include "../include/header.h"

t_intersection hit(t_list *xs)
{
	t_intersection	it;
	t_list		*temp;
	
	it.valid = false;
	bubbleSort(xs);
	while (xs != NULL)
	{
		temp = xs;
		if (temp->content.t >= 0)
		{
			it.t = temp->content.t ;
			it.object = temp->content.object;
			it.valid = true;
			break;
		}
		xs = temp->next;
	}
	return (it);
}
