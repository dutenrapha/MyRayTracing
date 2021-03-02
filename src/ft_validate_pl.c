#include "../include/header.h"

bool	ft_validate_pl(char **line_t)
{
    if(ft_strDlen(line_t) !=4)
    {
        ft_printf("Error\nUm plano deve conter extamente 4 parametros: o identificador pl, as coordenas da posicao x,y,z, o vetor normal e sua cor\n");
        return(false);
    }
    if(!is_coordenada(line_t[1]))
    {
       ft_printf("Error\nDigite uma coordenada valida para o plano\n");
       return(false);
    }
    if(!is_normal(line_t[2]))
    {
       ft_printf("Error\nDigite um vetor normal valido para o plano\n");
       return(false);
    }
    if(!is_color(line_t[3]))
    {
       ft_printf("Error\nDigite uma cor valida para o plano\n");
       return(false);
    }
    return(true);
}