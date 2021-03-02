#include "../include/header.h"

bool	ft_validate_A(char **line_t)
{
    if(ft_strDlen(line_t) !=3)
    {
        ft_printf("Error\nA luz ambiente deve conter extamente 3 parametros: o identificador A, o tamanho de x e o tamanho de y\n");
        return(false);
    }
    if (!ft_isdigit(*line_t[1]) || ft_atof(line_t[1]) < 0 || ft_atof(line_t[1]) > 1)
    {
       ft_printf("Error\nO valor de lighting ratio, da luz ambiente, de ser um numero e estar no intervalor [0.0,1.0]\n");
       return(false);
    }
    if(!is_color(line_t[2]))
    {
       ft_printf("Error\nDigite uma cor valida para a luz ambiente\n");
       return(false);
    }
    
    return(true);
}