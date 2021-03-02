#include "../include/header.h"

bool	ft_validate_tr(char **line_t)
{
    if(ft_strDlen(line_t) !=5)
    {
        ft_printf("Error\nUm triangulo deve conter extamente 5 parametros: o identificador tr, 3 coordenadas x,y,z, referentes aos vertices do triangulo e a sua cor\n");
        return(false);
    }
    if(!is_coordenada(line_t[1]))
    {
       ft_printf("Error\nDigite uma coordenada valida para o triangulo\n");
       return(false);
    }
    if(!is_coordenada(line_t[2]))
    {
       ft_printf("Error\nDigite uma coordenada valida para o triangulo\n");
       return(false);
    }
    if(!is_coordenada(line_t[3]))
    {
       ft_printf("Error\nDigite uma coordenada valida para o triangulo\n");
       return(false);
    }
    if(!is_color(line_t[4]))
    {
       ft_printf("Error\nDigite uma cor valida para o triangulo\n");
       return(false);
    }
    return(true);
}