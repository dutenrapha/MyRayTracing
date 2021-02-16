#include "../include/header.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (new)
		new->content = content;
	new->next = NULL;
	return (new);
}