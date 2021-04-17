/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 02:15:54 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 02:19:57 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

bool	ft_validate_a(char **line_t)
{
	if (ft_str_dlen(line_t) != 3)
	{
		ft_printf("Error\nA luz ambiente deve conter extamente 3 parametros:");
		ft_printf("o identificador A, o tamanho de x e o tamanho de y\n");
		return (false);
	}
	if (!ft_isdigit(*line_t[1]) ||
	ft_atof(line_t[1]) < 0 ||
	ft_atof(line_t[1]) > 1)
	{
		ft_printf("Error\nO valor de lighting ratio, da luz ambiente, ");
		ft_printf("de ser um numero ");
		ft_printf("e estar no intervalor [0.0,1.0]\n");
		return (false);
	}
	if (!is_color(line_t[2]))
	{
		ft_printf("Error\nDigite uma cor valida para a luz ambiente\n");
		return (false);
	}
	return (true);
}
