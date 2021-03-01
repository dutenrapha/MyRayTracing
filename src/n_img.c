#include "../include/header.h"

void n_img(t_imgg **l, t_data img)
{
    t_imgg *temp;
    if(ft_lstsize_img(*l) == 0)
    {
        *l = ft_lstnew_img(img);
    }
    else
    {
		temp = *l;
		while (temp->next)
		{
			temp = temp->next;
		}
        temp->next = ft_lstnew_img(img);
    }
}
