/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 02:12:12 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 02:12:34 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return (sub(in, multi(normal, 2 * dot(in, normal))));
}
