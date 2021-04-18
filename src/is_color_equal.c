/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_color_equal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:36:35 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 23:40:09 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

bool	is_color_equal(t_color c1, t_color c2)
{
	if (fabs(c1.red - c2.red) > EPSILON)
	{
		return (false);
	}
	else if (fabs(c1.green - c2.green) > EPSILON)
	{
		return (false);
	}
	else if (fabs(c1.blue - c2.blue) > EPSILON)
	{
		return (false);
	}
	else
	{
		return (true);
	}
}
