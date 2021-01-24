#include "../include/header.h"

static void swap(t_intersection *xs, int i) 
{ 
    t_intersection temp1;
    t_intersection temp2;

    temp1 = xs[i];
    temp2 = xs[i + 1];
    xs[i] = temp2;
    xs[i + 1] = temp1; 
} 

t_intersection *bubbleSort(t_intersection *xs, int lenght) 
{
	int	swapped;
    int i;
  
    if (xs == NULL) 
        return (xs); 
  
    do
    { 
        swapped = 0; 
        i = 0;
        while (i < lenght -1) 
        { 
            if (xs[i].t > xs[i + 1].t) 
            {  
                swap(xs,i); 
                swapped = 1; 
            } 
            i++;
        }
    } 
    while (swapped); 
    return (xs);
}
