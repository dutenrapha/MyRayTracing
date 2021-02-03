#include "../include/header.h"

// static	int size_xs(t_object *objects, int *status, int n)
// {
// 	int resp;
// 	int i;

// 	i = 0;
// 	resp = 0;
// 	while (i < n)
// 	{
// 		if (status[i] == 1)
// 		{
// 			if (ft_memcmp(objects[i].type,"plan") == 0)
// 			{
// 				resp++;
// 			}
// 			else
// 			{
// 				resp = resp + 2;
// 			}
// 		}
// 		i++;
// 	}
// 	return (resp);
// }

t_intersection  *intersect_world(t_world w, t_ray r, int *lenght)
{
	t_intersection	*xs;
	t_intersection	*init;
	int		i;
	int 	j;
	int 	k;
	//int		*status;
	int		num_inter;
	int		*num;

	num_inter = 0;
	num = &num_inter;
	//status = NULL;
	//status = (int *)malloc(sizeof(int)*w.num_objects);
	k = 0;
	i = 0;
	while(i < w.num_objects)
	{
		init = intersect(w.objects[i],r,num);
		k = k + num_inter;
		num_inter = 0;
		//status[i] = 0;
		if (init != NULL)
		{
			//status[i] = 1;
			free(init);
			init = NULL;
		}
		i++;
	}
	
	//k = size_xs(w.objects,status,w.num_objects);
	if (k > 0)
	{
		xs = (t_intersection *)malloc(sizeof(t_intersection)*k);
		i = 0;
		j = 0;
		while(i < w.num_objects)
		{
			//if (status[i] == 1)
			//{
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
						//free(init);
					}
				}
			//}
			i++;
		}
	}
	else
	{
		xs = NULL;
	}
	bubbleSort(xs,k);
	*lenght = k;
	//free(status);
	return (xs);
}
