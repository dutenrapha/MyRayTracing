/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:26:30 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 19:26:43 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_ray	transform(t_ray r, t_matrix m)
{
	t_ray resp;

	resp.origin = matrix_multi_vec(m, r.origin);
	resp.direction = matrix_multi_vec(m, r.direction);
	return (resp);
}
