#include "../include/header.h"

t_intersection  *intersect_world(t_world w, t_ray r, int *lenght)
{
	t_intersection	*xs;
	t_intersection	*resp;
	t_intersection	*init;
	int		i;
	int 	j;
	int		n_inter;
	int 	k;
	int		y;

	y = 0;
	k = 0;
	n_inter = 0;
	i = 0;
	while(i < w.num_objects)
	{
		init = intersect(w.objects[i],r);
			if (init != NULL)
			{
				n_inter++;
				free(init);
				init = NULL;
			}
		i++;
	}
	if (n_inter > 0)
	{
		k = n_inter*2;
		xs = (t_intersection *)malloc(sizeof(t_intersection)*k);
		i = 0;
		j = 0;
		while(i < w.num_objects)
		{
			init = intersect(w.objects[i],r);
				if (init != NULL)
				{
					xs[y + j] = init[0];
					j++;
					xs[y + j] = init[1];
					free(init);
					init = NULL;
					y++;
				}
			i++;
		}
	}
	else
	{
		xs = NULL;
	}
	resp = (t_intersection *)malloc(sizeof(t_intersection)*k);
	resp = bubbleSort(xs,n_inter*2);
	free(xs);
	*lenght = n_inter*2;
	return (resp);
}
