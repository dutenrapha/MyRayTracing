/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:28:23 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 01:28:38 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_light	point_light(t_tuple position, t_color intensity)
{
	t_light	resp;

	resp.position = position;
	resp.intensity = intensity;
	return (resp);
}
