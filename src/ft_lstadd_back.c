#include "../include/header.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{	t_list	*aux;

	aux = (*lst);
	if (!new)
		return ;
	if (!*lst)
		(*lst) = new;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
}