#include "../include/header.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (lst)
	{
		while (*lst)
		{
			temp = *lst;
			*lst = temp->next;
			free(temp);
		}
	}
	*lst = NULL;
}