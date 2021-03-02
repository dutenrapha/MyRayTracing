#include "../include/header.h"

bool	ft_validate_c(char **line_t)
{
    if(ft_strDlen(line_t) !=4)
    {
        ft_printf("Error\nUma camera deve conter extamente 4 parametros: o identificador c, as coordenas da posicao x,y,z, o vetor normal e o FOV\n");
        return(false);
    }
    if(!is_coordenada(line_t[1]))
    {
       ft_printf("Error\nDigite uma coordenada valida para a camera\n");
       return(false);
    }
    if(!is_normal(line_t[2]))
    {
       ft_printf("Error\nDigite um vetor normal valido para a camera\n");
       return(false);
    }
    if (!is_num(line_t[3]))
    {
       ft_printf("Error\nDigite um valor FOV entre [0.0,180.0] para o FOV da camera\n");
       return(false);
    }
    if ( ft_atof(line_t[3]) < 0 || ft_atof(line_t[3]) > 180)
    {
       ft_printf("Error\nDigite um valor FOV entre [0.0,180.0] para o FOV da camera\n");
       return(false);
    }
    return(true);
}