#include "../include/header.h"

// void	ft_lstclear(t_list **lst)
// {
// 	t_list *aux;

// 	if (!*lst)
// 		return ;
// 	while ((*lst) != NULL)
// 	{
// 		aux = (*lst)->next;
// 		free(*lst);
// 		*lst = aux;
// 	}
// 	*lst = 0;

// }
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



// void	ft_lstclear(t_list **lst)
// {
// 	if ((*lst)->next)
// 		ft_lstclear(&(*lst)->next);
// 	free(*lst);
// 	*lst = NULL;
// }

// void	ft_lstclear(t_list **lst)
// {
// 	t_list	*temp;

// 	if (lst)
// 	{
// 		while (*lst)
// 		{
// 			temp = *lst;
// 			*lst = temp->next;
// 			free(temp);
// 		}
// 	}
// 	*lst = NULL;
// }