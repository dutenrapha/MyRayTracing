/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:24:58 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 19:25:52 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_shape	test_shape(void)
{
	t_shape	s;

	s.transform = identity();
	s.material = material();
	s.saved_ray = ray(point(0, 0, 0), vector(0, 0, 0));
	return (s);
}
