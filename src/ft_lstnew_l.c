#include "../include/header.h"

t_lights	*ft_lstnew_l(t_light content)
{
	t_lights	*new;

	if (!(new = (t_lights *)malloc(sizeof(t_lights))))
		return (NULL);
	if (new)
		new->content = content;
	new->next = NULL;
	return (new);
}