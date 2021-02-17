#include "../include/header.h"

void	ft_lstclear(t_list **lst)
{
	t_list *current;
	t_list *next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
   }
   *lst = NULL;
}


