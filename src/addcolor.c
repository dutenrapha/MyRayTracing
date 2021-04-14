/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:49:24 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/14 18:49:44 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_color	addcolor(t_color c1, t_color c2)
{
	t_color c;

	c.red = c1.red + c2.red;
	c.green = c1.green + c2.green;
	c.blue = c1.blue + c2.blue;
	return (c);
}
