#include "../include/header.h"

t_cv	*ft_lstnew_cv(t_canvas cv)
{
	t_cv	*new;

	if (!(new = (t_cv *)malloc(sizeof(t_cv))))
		return (NULL);
	if (new)
		new->content = cv;
	new->next = NULL;
	return (new);
}