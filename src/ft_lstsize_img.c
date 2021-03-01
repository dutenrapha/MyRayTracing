#include "../include/header.h"

int	ft_lstsize_img(t_imgg *img)
{
	int		i;
	t_imgg	*temp;

	if (img)
	{
		i = 1;
		temp = img;
		while (temp->next)
		{
			temp = temp->next;
			i++;
		}
		return (i);
	}
	else
		return (0);
}