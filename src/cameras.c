#include "../include/header.h"

void cameras(t_cameras **l, t_camera c)
{
    t_cameras *temp;
    if(ft_lstsize_c(*l) == 0)
    {
        *l = ft_lstnew_c(c);
    }
    else
    {
		temp = *l;
		while (temp->next)
		{
			temp = temp->next;
		}
        temp->next = ft_lstnew_c(c);
    }
}
