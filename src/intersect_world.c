#include "../include/header.h"


t_intersection  *intersect_world(t_world w, t_ray r, int *lenght)
{
	t_intersection	*xs;
	t_intersection	*init;
	int		i;
	int 	j;
	int 	k;
	int		num_inter;
	int		*num;

	num_inter = 0;
	num = &num_inter;
	k = 0;
	i = 0;
	while(i < w.num_objects)
	{
		init = intersect(w.objects[i],r,num);
		k = k + num_inter;
		num_inter = 0;
		if (init != NULL)
		{
			free(init);
			init = NULL;
		}
		i++;
	}
	if (k > 0)
	{
		xs = (t_intersection *)malloc(sizeof(t_intersection)*k);
		i = 0;
		j = 0;
		while(i < w.num_objects)
		{
				if(ft_memcmp(w.objects[i].type,"plan") == 0)
				{
					init = intersect(w.objects[i],r, num);
					if (init != NULL)
					{
						xs[j] = init[0];
						j++;
						free(init);
						init = NULL;
						num_inter = 0;
					}
				}
				else
				{
					init = intersect(w.objects[i],r, num);
					if (init != NULL)
					{
						if (num_inter == 1)
						{
							xs[j] = init[0];
							j++;
							free(init);
							init = NULL;
							num_inter = 0;
						}
						else
						{
							xs[j] = init[0];
							j++;
							xs[j] = init[1];
							j++;
							free(init);
							init = NULL;
							num_inter = 0;
						}
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
