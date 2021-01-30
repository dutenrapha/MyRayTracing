#include "../include/header.h"

static	int size_xs(t_object *objects, int *status, int n)
{
	int resp;
	int i;

	i = 0;
	while (i < n)
	{
		if (status[i] == 1)
		{
			if (ft_memcmp(objects[i].type,"plan") == 0)
			{
				resp++;
			}
			else
			{
				resp = resp + 2;
			}
		}
		i++;
	}
	return (resp);
}

t_intersection  *intersect_world(t_world w, t_ray r, int *lenght)
{
	t_intersection	*xs;
	t_intersection	*init;
	int		i;
	int 	j;
	int		n_inter;
	int 	k;
	int		*status;

	status = NULL;
	status = (int *)malloc(sizeof(int)*w.num_objects);
	k = 0;
	n_inter = 0;
	i = 0;
	while(i < w.num_objects)
	{
		init = intersect(w.objects[i],r);
		status[i] = 0;
		if (init != NULL)
		{
			status[i] = 1;
			n_inter++;
			free(init);
			init = NULL;
		}
		i++;
	}
	k = size_xs(w.objects,status,n_inter);
	if (k > 0)
	{
		xs = (t_intersection *)malloc(sizeof(t_intersection)*k);
		i = 0;
		j = 0;
		while(i < w.num_objects)
		{
			if (status[i] == 1)
			{
				if(ft_memcmp(w.objects[i].type,"plan") == 0)
				{
					init = intersect(w.objects[i],r);
					xs[j] = init[0];
					j++;
					free(init);
					init = NULL;
				}
				else
				{
					init = intersect(w.objects[i],r);
					xs[j] = init[0];
					j++;
					xs[j] = init[1];
					j++;
					free(init);
					init = NULL;
				}
			}
			i++;
		}
	}
	else
	{
		xs = NULL;
	}
	bubbleSort(xs,k);
	*lenght = k;
	return (xs);
}
