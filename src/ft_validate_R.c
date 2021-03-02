#include "../include/header.h"

bool	ft_validate_R(char **line_t)
{
    if(ft_strDlen(line_t) !=3)
    {
        ft_printf("Error\nA resolucao deve conter extamente 3 parametros: o identificador R, o tamanho de x e o tamanho de y\n");
        return(false);
    }
    if (!ft_isdigit(*line_t[1]))
    {
       ft_printf("Error\nO valor de x da resolucao deve ser um numero\n");
       return(false);
    }
    if (!ft_isdigit(*line_t[2]))
    {
       ft_printf("Error\nO valor de y da resolucao deve ser um numero\n");
       return(false);
    }
    if (ft_atof(line_t[1]) <0)
    {
        ft_printf("Error\nO valor de x da resolucao deve ser positivo\n");
       return(false);
    }
    if (ft_atof(line_t[2]) <0)
    {
        ft_printf("Error\nO valor de y da resolucao deve ser positivo\n");
        return(false);
    }
    return(true);
}