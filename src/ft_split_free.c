#include "../include/header.h"

void    ft_split_free(char ***split)
{
    char    **temp; 
    int     i;

    i = 0;
    temp = *split;
    while (temp[i] != NULL)
    {
        free(temp[i]);
        temp[i] = NULL;
        i++;
    }
    free(temp);
    temp = NULL;
}