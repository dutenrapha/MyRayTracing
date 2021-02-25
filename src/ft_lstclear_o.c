#include "../include/header.h"

void	ft_lstclear_o(t_objects **lst)
{
	t_objects *current;
	t_objects *next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
   }
   *lst = NULL;
}


