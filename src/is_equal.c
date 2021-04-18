/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_equal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:41:51 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 23:44:45 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

bool	is_equal(t_tuple v1, t_tuple v2)
{
	if (fabs(v1.x - v2.x) > EPSILON)
	{
		return (false);
	}
	else if (fabs(v1.y - v2.y) > EPSILON)
	{
		return (false);
	}
	else if (fabs(v1.z - v2.z) > EPSILON)
	{
		return (false);
	}
	else if (fabs(v1.w - v2.w) > EPSILON)
	{
		return (false);
	}
	else
	{
		return (true);
	}
}
