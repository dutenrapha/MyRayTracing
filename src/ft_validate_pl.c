/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_pl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 02:46:38 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 02:47:34 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

bool	ft_validate_pl(char **line_t)
{
	if (ft_str_dlen(line_t) != 4)
	{
		ft_printf("Error\nUm plano deve conter extamente 4 parametros:");
		ft_printf(" o identificador pl, as coordenas da posicao x,y,z, o");
		ft_printf(" vetor normal e sua cor\n");
		return (false);
	}
	if (!is_coordenada(line_t[1]))
	{
		ft_printf("Error\nDigite uma coordenada valida para o plano\n");
		return (false);
	}
	if (!is_normal(line_t[2]))
	{
		ft_printf("Error\nDigite um vetor normal valido para o plano\n");
		return (false);
	}
	if (!is_color(line_t[3]))
	{
		ft_printf("Error\nDigite uma cor valida para o plano\n");
		return (false);
	}
	return (true);
}
