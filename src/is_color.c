#include "../include/header.h"

bool is_color(char *s)
{
    char **temp;
    float R;
    float G;
    float B;

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
    R = (float)ft_atoi(temp[0]);
    G = (float)ft_atoi(temp[1]);
    B = (float)ft_atoi(temp[2]);
    if (R < 0 || R > 255 || G < 0 || G > 255 || B < 0 || B > 255 )
    {
        ft_split_free(&temp);
        return(false);
    }
    ft_split_free(&temp);
    return(true);
}