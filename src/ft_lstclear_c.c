#include "../include/header.h"

void	ft_lstclear_c(t_cameras **lst)
{
	t_cameras *current;
	t_cameras *next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
   }
   *lst = NULL;
}


