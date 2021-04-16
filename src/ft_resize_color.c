/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 01:23:52 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 01:26:46 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	ft_resize_color(float a)
{
	if (a >= 1)
	{
		return (255);
	}
	else if (a <= 0)
	{
		return (0);
	}
	else
	{
		return (ceil(255 * a));
	}
}
