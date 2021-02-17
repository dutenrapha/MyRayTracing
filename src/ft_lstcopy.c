#include "../include/header.h"

t_list *ft_lstcopy(t_list *new)
{
    t_list *lst;
    if (new == NULL)
    {
        return NULL;
    }
    lst = (t_list *)malloc(sizeof(t_list)); 
    lst->content = new->content;
    lst->next = ft_lstcopy(new->next);
    return lst;
}