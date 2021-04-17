/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_tr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 02:58:39 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 03:00:11 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static bool	ft_axu(char **line_t)
{
	if (ft_str_dlen(line_t) != 5)
	{
		ft_printf("Error\nUm triangulo deve conter extamente 5 parametros:");
		ft_printf(" o identificador tr, 3 coordenadas x,y,z, referentes aos");
		ft_printf(" vertices do triangulo e a sua cor\n");
		return (false);
	}
	if (!is_coordenada(line_t[1]))
	{
		ft_printf("Error\nDigite uma coordenada valida para o triangulo\n");
		return (false);
	}
	return (true);
}

bool		ft_validate_tr(char **line_t)
{
	if (ft_axu(line_t) == false)
		return (false);
	if (!is_coordenada(line_t[2]))
	{
		ft_printf("Error\nDigite uma coordenada valida para o triangulo\n");
		return (false);
	}
	if (!is_coordenada(line_t[3]))
	{
		ft_printf("Error\nDigite uma coordenada valida para o triangulo\n");
		return (false);
	}
	if (!is_color(line_t[4]))
	{
		ft_printf("Error\nDigite uma cor valida para o triangulo\n");
		return (false);
	}
	return (true);
}
