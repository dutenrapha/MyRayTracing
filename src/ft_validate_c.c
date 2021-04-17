/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 02:21:58 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 02:33:09 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static bool	ft_axu(char **line_t)
{
	if (ft_str_dlen(line_t) != 4)
	{
		ft_printf("Error\nUma camera deve conter ");
		ft_printf("extamente 4 parametros: ");
		ft_printf("o identificador c, as coordenas da posicao x,y,z,");
		ft_printf(" o vetor normal e o FOV\n");
		return (false);
	}
	return (true);
}

bool		ft_validate_c(char **line_t)
{
	if (ft_axu(line_t) == false)
		return (false);
	if (!is_coordenada(line_t[1]))
	{
		ft_printf("Error\nDigite uma coordenada valida para a camera\n");
		return (false);
	}
	if (!is_normal(line_t[2]))
	{
		ft_printf("Error\nDigite um vetor normal valido para a camera\n");
		return (false);
	}
	if (!is_num(line_t[3]))
	{
		ft_printf("Error\nDigite um valor FOV entre [0.0,180.0] para o");
		ft_printf("FOV da camera\n");
		return (false);
	}
	if (ft_atof(line_t[3]) < 0 || ft_atof(line_t[3]) > 180)
	{
		ft_printf("Error\nDigite um valor FOV entre [0.0,180.0] para o ");
		ft_printf("FOV da camera\n");
		return (false);
	}
	return (true);
}
