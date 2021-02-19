#include "../include/header.h"

int	ft_lstsize_l(t_lights *lst)
{
	int		i;
	t_lights	*temp;

	if (lst)
	{
		i = 1;
		temp = lst;
		while (temp->next)
		{
			temp = temp->next;
			i++;
		}
		return (i);
	}
	else
		return (0);
}