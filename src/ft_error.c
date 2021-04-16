/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 00:51:29 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 00:51:31 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

char	*ft_error(char *error)
{
	if (ft_memcmp("000", error, 4) == 0)
	{
		return ("Error\nNao foi possivel abrir o arquivo");
	}
	if (ft_memcmp("001", error, 4) == 0)
	{
		return ("Error\nVoce nao digitou o nome do arquivo");
	}
	else if (ft_memcmp("002", error, 4) == 0)
	{
		return ("Error\nVoce digitou mais do que 3 parametros");
	}
	else if (ft_memcmp("003", error, 4) == 0)
	{
		return ("Error\nEsse nao e um arquivo .rt");
	}
	else if (ft_memcmp("004", error, 4) == 0)
	{
		return ("Error\nVoce nao especificou a flag --save");
	}
	return ("Error\nFatal Error");
}
