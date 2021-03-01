#include "../include/header.h"

int	ft_lstsize_cv(t_cv *cv)
{
	int		i;
	t_cv	*temp;

	if (cv)
	{
		i = 1;
		temp = cv;
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