#include "../include/header.h"

bool	ft_validate_sq(char **line_t)
{
    if(ft_strDlen(line_t) !=5)
    {
        ft_printf("Error\nUm quadrado deve conter extamente 5 parametros: o identificador sq, as coordenas da posicao x,y,z, o vetor normal, o tamanho do lado e sua cor\n");
        return(false);
    }
    if(!is_coordenada(line_t[1]))
    {
       ft_printf("Error\nDigite uma coordenada valida para o quadrado\n");
       return(false);
    }
    if(!is_normal(line_t[2]))
    {
       ft_printf("Error\nDigite um vetor normal valido para o quadrado\n");
       return(false);
    }
    if (!is_num(line_t[3]))
    {
       ft_printf("Error\nO lado de um quadrado deve ser um numero\n");
       return(false);
    }
    if ( ft_atof(line_t[3]) < 0)
    {
       ft_printf("Error\nO lado de um quadrado deve ser um valor positivo\n");
       return(false);
    }
    if(!is_color(line_t[4]))
    {
       ft_printf("Error\nDigite uma cor valida para o quadrado\n");
       return(false);
    }
    return(true);
}