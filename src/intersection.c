/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:45:32 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 22:47:31 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_intersection	intersection(float t, t_object o)
{
	t_intersection i;

	i.t = t;
	i.object = o;
	i.valid = true;
	return (i);
}
