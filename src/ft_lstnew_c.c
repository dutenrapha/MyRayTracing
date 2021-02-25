#include "../include/header.h"

t_cameras	*ft_lstnew_c(t_camera content)
{
	t_cameras	*new;

	if (!(new = (t_cameras *)malloc(sizeof(t_cameras))))
		return (NULL);
	if (new)
		new->content = content;
	new->next = NULL;
	return (new);
}