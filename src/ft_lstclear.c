#include "../include/header.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (*lst != NULL)
	{
		while ((*lst)->next != NULL)
		{
			temp = *lst;
			*lst = temp->next;
			free(temp);
		}
	}
	*lst = NULL;
}
