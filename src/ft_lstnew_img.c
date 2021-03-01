#include "../include/header.h"

t_imgg	*ft_lstnew_img(t_data img)
{
	t_imgg	*new;

	if (!(new = (t_imgg *)malloc(sizeof(t_imgg))))
		return (NULL);
	if (new)
		new->content = img;
	new->next = NULL;
	return (new);
}