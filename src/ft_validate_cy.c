#include "../include/header.h"

bool	ft_validate_cy(char **line_t)
{
    if(ft_strDlen(line_t) !=6)
    {
        ft_printf("Error\nUm cilindro deve conter extamente 6 parametros: o identificador cy, as coordenas da posicao x,y,z, o vetor normal, o diametro do cilindro, a altura do cilindro e a sua cor\n");
        return(false);
    }
    if(!is_coordenada(line_t[1]))
    {
       ft_printf("Error\nDigite uma coordenada valida para o cilindro\n");
       return(false);
    }
    if(!is_normal(line_t[2]))
    {
       ft_printf("Error\nDigite um vetor normal valido para o cilindro\n");
       return(false);
    }
    if (!is_num(line_t[3]))
    {
       ft_printf("Error\nO diametro de um cilindro deve ser um numero\n");
       return(false);
    }
    if ( ft_atof(line_t[3]) < 0)
    {
       ft_printf("Error\nO diametro de um cilindro deve ser um valor positivo\n");
       return(false);
    }
    if (!is_num(line_t[4]))
    {
       ft_printf("Error\nA altura de um cilindro deve ser um numero\n");
       return(false);
    }
    if ( ft_atof(line_t[4]) < 0)
    {
       ft_printf("Error\nA altura de um cilindro deve ser um valor positivo\n");
       return(false);
    }
    if(!is_color(line_t[5]))
    {
       ft_printf("Error\nDigite uma cor valida para o cilindro\n");
       return(false);
    }
    return(true);
}