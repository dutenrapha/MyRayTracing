#include "../include/header.h"

bool	ft_checkSave(int argc)
{
    bool resp;

    resp = false;
    if (argc == 3)
	{
        resp = true;
	}
    return(resp);
}