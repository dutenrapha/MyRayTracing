#include "../include/header.h"

void cv(t_cv **l, t_canvas cv)
{
    t_cv *temp;
    if(ft_lstsize_cv(*l) == 0)
    {
        *l = ft_lstnew_cv(cv);
    }
    else
    {
		temp = *l;
		while (temp->next)
		{
			temp = temp->next;
		}
        temp->next = ft_lstnew_cv(cv);
    }
}
