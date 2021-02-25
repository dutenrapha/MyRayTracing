#include "../include/header.h"

void objects(t_objects **l, t_object o)
{
    t_objects *temp;
    if(ft_lstsize_o(*l) == 0)
    {
        *l = ft_lstnew_o(o);
    }
    else
    {
		temp = *l;
		while (temp->next)
		{
			temp = temp->next;
		}
        temp->next = ft_lstnew_o(o);
    }
}
