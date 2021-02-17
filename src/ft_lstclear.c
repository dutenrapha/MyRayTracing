#include "../include/header.h"

void	ft_lstclear(t_list **lst)
{
	t_list *aux;

	if (!*lst)
		return ;
	while (*lst == NULL)
	{
		aux = (*lst)->next;
		free(*lst);
		*lst = aux;
	}
	*lst = 0;
}