#include "../include/header.h"

bool is_coordenada(char *s)
{
    char **temp;

    temp = ft_split(s,',');
    if (ft_strDlen(temp) !=3)
    {
        ft_split_free(&temp);
        return(false);
    }
    if (!is_num(temp[0]) || !is_num(temp[1]) || !is_num(temp[2]))
    {
        ft_split_free(&temp);
        return(false);
    }
    ft_split_free(&temp);
    return(true);
}