#include "../include/header.h"

t_intersection *intersections(int count,...)
{
	t_intersection	*xs;

	va_list args;
	int i;

	if (count >0)
	{
		xs = (t_intersection *)malloc(sizeof(t_intersection)*count);
		va_start(args, count);
		i = 0;
		while (i < count)
		{
			xs[i] = va_arg(args, t_intersection);
			i++;	
		}		
		va_end(args);	
	}
	else
	{
		xs = NULL;
	}
	return (xs);
}
