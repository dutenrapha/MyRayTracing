#include "../include/header.h"

t_world world(int num_objects,...)
{
	t_world		w;
	int 		i;
	t_object	obj;
	va_list		args;

	w.num_objects = num_objects;
	w.objects = NULL;
        w.has_light = false;
	if (w.num_objects > 0)
	{
		va_start(args, num_objects);
		w.objects = (t_object *)malloc(sizeof(t_object)*num_objects);
		i = 0;
		while (i < num_objects)
		{
			obj = va_arg(args, t_object);
			w.objects[i] = obj;
			i++;
		}	
		va_end(args);
	}
	return (w);
}
