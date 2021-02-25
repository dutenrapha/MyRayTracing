#include "../include/header.h"

int	ft_lstsize_o(t_objects *lst)
{
	int		i;
	t_objects	*temp;

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