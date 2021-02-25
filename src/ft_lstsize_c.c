#include "../include/header.h"

int	ft_lstsize_c(t_cameras *lst)
{
	int		i;
	t_cameras	*temp;

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