#include "../include/header.h"

// static void swap(t_list **xs) 
// { 
//     t_intersection temp;
    
//     temp = (*xs)->content;
//     (*xs)->next->content = (*xs)->content;
//     (*xs)->content = temp;
// } 

// void bubbleSort2(t_list *xs) 
// {
// 	int	swapped;
//     int i;
//     int lenght;

//     lenght = ft_lstsize(xs);
  
//     if (xs == NULL) 
//         return ; 
  
//     do
//     { 
//         swapped = 0; 
//         i = 0;
//         while (i < lenght -1) 
//         {
//             if (xs->content.t > xs->next->content.t)
//             {  
//                 swap(&xs); 
//                 swapped = 1; 
//             } 
//             i++;
//         }
//     } 
//     while (swapped);
// }


static t_list* swap(t_list *ptr1, t_list *ptr2) 
{ 
    t_list *tmp; 

    tmp = ptr2->next;
    ptr2->next = ptr1; 
    ptr1->next = tmp; 
    return ptr2; 
} 

void bubbleSort2(t_list **xs) 
{
    t_list **temp;
    t_list *p1;
    t_list *p2;
    int i;
    int j;
    int n;
    bool swapped;

    i = 1;
    n = ft_lstsize(*xs);
    while (i < n)
    {
        j = 0;
        temp = xs; 
        swapped = 0;
        while (j < n - i -1)
        {
            p1 = *temp;
            p2 = (*temp)->next;
            if (p1->content.t > p2->content.t) 
            { 
                *temp = swap(p1, p2); 
                swapped = 1; 
            }
            temp = &(*temp)->next; 
            j++;
        }
        if (swapped == 0) 
            break; 
        i++;
    }
}