#include "../include/header.h"

bool is_num(char *s)
{
    int i;
    
    if (    !(s[0]== '-' || ft_isdigit(s[0]))    ) 
    {
        return(false);
    }
    i = 1;
    while (s[i] != '\0')
    {
        if (!ft_isdigit(s[i]))
        {
            if ( !(s[i] == '.'))
            {
                return(false);
            }
        }
        i++;
    }
    return (true);
}