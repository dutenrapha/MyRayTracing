#include "../include/header.h"

t_list *intersections(int count,...)
{
	t_list	*xs;
	t_list  *temp;
	t_intersection intersec;
	va_list args;
	int i;
	
	va_start(args, count);
	intersec = va_arg(args, t_intersection);	
	xs = ft_lstnew(intersec);
	i = 1;
	while (i < count)
	{
		intersec = va_arg(args, t_intersection);
		temp = ft_lstnew(intersec);
		ft_lstadd_back(&xs, temp);
		ft_lstclear(&temp);
		i++;	
	}		
	va_end(args);	
	return xs;
}
