#include "../include/header.h"

static void swap(t_list **xs) 
{ 
    t_intersection temp;
    
    temp = (*xs)->content;
    (*xs)->next->content = (*xs)->content;
    (*xs)->content = temp;
} 

void bubbleSort2(t_list *xs) 
{
	int	swapped;
    int i;
    int lenght;

    lenght = ft_lstsize(xs);
  
    if (xs == NULL) 
        return ; 
  
    do
    { 
        swapped = 0; 
        i = 0;
        while (i < lenght -1) 
        {
            if (xs->content.t > xs->next->content.t)
            {  
                swap(&xs); 
                swapped = 1; 
            } 
            i++;
        }
    } 
    while (swapped);
}
