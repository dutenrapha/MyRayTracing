/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_cy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 02:36:07 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 02:42:10 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static bool	ft_axu(char **line_t)
{
	if (ft_str_dlen(line_t) != 6)
	{
		ft_printf("Error\nUm cilindro deve conter extamente 6 parametros:");
		ft_printf(" o identificador cy, as coordenas da posicao x,y,z, o ");
		ft_printf("vetor normal, o diametro do cilindro, a altura do cilindro");
		ft_printf(" e a sua cor\n");
		return (false);
	}
	return (true);
}

static bool	ft_axu1(char **line_t)
{
	if (ft_atof(line_t[3]) < 0)
	{
		ft_printf("Error\nO diametro de um cilindro deve ser um valor ");
		ft_printf("positivo\n");
		return (false);
	}
	return (true);
}

static bool	ft_axu2(char **line_t)
{
	if (!is_num(line_t[4]))
	{
		ft_printf("Error\nA altura de um cilindro deve ser um numero\n");
		return (false);
	}
	if (ft_atof(line_t[4]) < 0)
	{
		ft_printf("Error\nA altura de um cilindro deve ser um valor");
		ft_printf(" positivo\n");
		return (false);
	}
	if (!is_color(line_t[5]))
	{
		ft_printf("Error\nDigite uma cor valida para o cilindro\n");
		return (false);
	}
	return (true);
}

bool		ft_validate_cy(char **line_t)
{
	if (ft_axu(line_t) == false)
		return (false);
	if (!is_coordenada(line_t[1]))
	{
		ft_printf("Error\nDigite uma coordenada valida para o cilindro\n");
		return (false);
	}
	if (!is_normal(line_t[2]))
	{
		ft_printf("Error\nDigite um vetor normal valido para o cilindro\n");
		return (false);
	}
	if (!is_num(line_t[3]))
	{
		ft_printf("Error\nO diametro de um cilindro deve ser um numero\n");
		return (false);
	}
	if (ft_axu1(line_t) == false)
		return (false);
	if (ft_axu2(line_t) == false)
		return (false);
	return (true);
}
