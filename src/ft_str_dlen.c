/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strDlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 02:07:09 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 02:07:11 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	ft_str_dlen(char **s)
{
	int len;

	if (!s)
		return (0);
	len = 0;
	while (*s++)
	{
		len++;
	}
	return (len);
}
