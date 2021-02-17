#include "../include/header.h"

t_objects	*ft_lstnew_w(t_object content)
{
	t_objects	*new;

	if (!(new = (t_objects *)malloc(sizeof(t_objects))))
		return (NULL);
	if (new)
		new->content = content;
	new->next = NULL;
	return (new);
}