/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multicolorS.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 00:29:20 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 00:29:24 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_color	multicolor_s(t_color c1, float a)
{
	t_color	c;

	c.red = c1.red * a;
	c.green = c1.green * a;
	c.blue = c1.blue * a;
	return (c);
}
