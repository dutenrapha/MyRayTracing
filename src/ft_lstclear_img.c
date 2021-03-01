#include "../include/header.h"

void	ft_lstclear_img(t_imgg **img)
{
	t_imgg *current;
	t_imgg *next;

	current = *img;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
   }
   *img = NULL;
}


