#include "../include/header.h"

char	*ft_error(char* error)
{
    if (ft_memcmp("001",error,4) == 0)
    {
        return("Voce nao digitou o nome do arquivo");
    }
    else if (ft_memcmp("002",error,4) == 0)
    {
        return("Voce digitou mais do que 3 parametros");
    }
        else if (ft_memcmp("003",error,4) == 0)
    {
        return("Voce nao especificou a flag --save");
    }
    return("Fatal Error");
}