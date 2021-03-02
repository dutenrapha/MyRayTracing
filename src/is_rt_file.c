#include "../include/header.h"

bool 	is_rt_file(char *file)
{
    char *temp;
    bool resp;

    resp = false;
    temp = ft_strchr(file,'.');
    if (ft_memcmp(".rt",temp,4) == 0)
    {
        resp = true;
    }
    return(resp);
}