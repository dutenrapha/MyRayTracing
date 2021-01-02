#include "../include/header.h"

static void swap(t_list *a, t_list *b) 
{ 
    int temp = a->content.t; 
    a->content.t = b->content.t; 
    b->content.t = temp; 
} 

void bubbleSort(t_list *xs) 
{
	int	swapped;
	t_list	*ptr1;
	t_list	*lptr = NULL; 
  
    if (xs == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = xs; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->content.t > ptr1->next->content.t) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
}
