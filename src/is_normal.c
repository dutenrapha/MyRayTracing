#include "../include/header.h"

static bool is_unit(float x, float y, float z)
{
    if ( sqrt(x*x + y*y + z*z) - 1 < EPSILON)
    {
        return (true);
    }
    return (false);
}

bool is_normal(char *s)
{
    char **temp;
    float x;
    float y;
    float z;

    temp = ft_split(s,',');
    if (ft_strDlen(temp) !=3)
    {
        ft_split_free(&temp);
        return(false);
    }    
    if ( !(is_num(temp[0]) || is_num(temp[1]) || is_num(temp[2]) )  )
    {
        ft_split_free(&temp);
        return (false);
    }
    x = ft_atof(temp[0]);
    y = ft_atof(temp[1]);
    z = ft_atof(temp[2]);
    if (!is_unit(x,y,z))
    {
        ft_split_free(&temp);
        return (false);
    }
    ft_split_free(&temp);
    return (true);
}