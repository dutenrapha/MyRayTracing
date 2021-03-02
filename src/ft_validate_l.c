#include "../include/header.h"

bool	ft_validate_l(char **line_t)
{
    if(ft_strDlen(line_t) !=4)
    {
        ft_printf("Error\nUma luz deve conter extamente 4 parametros: o identificador l, as coordenas da posicao x,y,z, o  light brightness ratio e a cor da luz\n");
        return(false);
    }
    if(!is_coordenada(line_t[1]))
    {
       ft_printf("Error\nDigite uma coordenada valida para a luz\n");
       return(false);
    }
    if (!is_num(line_t[2]))
    {
       ft_printf("Error\nDigite um valor de light brightness ratio entre [0.0,1.0]\n");
       return(false);
    }
    if ( ft_atof(line_t[2]) < 0 || ft_atof(line_t[2]) > 1)
    {
       ft_printf("Error\nDigite um valor de light brightness ratio entre [0.0,1.0]\n");
       return(false);
    }
    if(!is_color(line_t[3]))
    {
       ft_printf("Error\nDigite uma cor valida para a luz\n");
       return(false);
    }
    return(true);
}