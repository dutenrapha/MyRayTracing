#include "../include/header.h"

void	ft_lstclear_l(t_lights **lst)
{
	t_lights *current;
	t_lights *next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
   }
   *lst = NULL;
}


