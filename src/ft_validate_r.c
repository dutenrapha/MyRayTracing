/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 02:48:09 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 02:52:11 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static bool	ft_axu(char **line_t)
{
	if (ft_str_dlen(line_t) != 3)
	{
		ft_printf("Error\nA resolucao deve conter extamente 3 ");
		ft_printf("parametros: o identificador R, o tamanho de x");
		ft_printf(" e o tamanho de y\n");
		return (false);
	}
	return (true);
}

bool		ft_validate_r(char **line_t)
{
	if (ft_axu(line_t) == false)
		return (false);
	if (!ft_isdigit(*line_t[1]))
	{
		ft_printf("Error\nO valor de x da resolucao deve ser um numero\n");
		return (false);
	}
	if (!ft_isdigit(*line_t[2]))
	{
		ft_printf("Error\nO valor de y da resolucao deve ser um numero\n");
		return (false);
	}
	if (ft_atof(line_t[1]) < 0)
	{
		ft_printf("Error\nO valor de x da resolucao deve ser positivo\n");
		return (false);
	}
	if (ft_atof(line_t[2]) < 0)
	{
		ft_printf("Error\nO valor de y da resolucao deve ser positivo\n");
		return (false);
	}
	return (true);
}
