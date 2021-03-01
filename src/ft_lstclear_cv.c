#include "../include/header.h"

void	ft_lstclear_cv(t_cv **cv)
{
	t_cv *current;
	t_cv *next;

	current = *cv;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
   }
   *cv = NULL;
}


