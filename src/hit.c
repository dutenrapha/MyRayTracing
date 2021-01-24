#include "../include/header.h"

t_intersection hit(t_intersection *xs, int lenght)
{
	t_intersection	it;
	int i;

	i = 0;
	it.valid = false;
	bubbleSort(xs,lenght);
	while (i < lenght)
	{
		if(xs[i].t > 0)
		{
			it.t = xs[i].t ;
			it.object = xs[i].object;
			it.valid = true;
			break;
		}
		i++;
	}
	return (it);
}
