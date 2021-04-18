/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:31:56 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 20:09:54 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static	void	f_aux(t_matrix *orientation, t_par9 p)
{
	write_matrix(orientation, 0, 0, p.left.x);
	write_matrix(orientation, 0, 1, p.left.y);
	write_matrix(orientation, 0, 2, p.left.z);
	write_matrix(orientation, 0, 3, 0.0);
	write_matrix(orientation, 1, 0, p.true_up.x);
	write_matrix(orientation, 1, 1, p.true_up.y);
	write_matrix(orientation, 1, 2, p.true_up.z);
	write_matrix(orientation, 1, 3, 0.0);
	write_matrix(orientation, 2, 0, -p.forward.x);
	write_matrix(orientation, 2, 1, -p.forward.y);
	write_matrix(orientation, 2, 2, -p.forward.z);
	write_matrix(orientation, 2, 3, 0.0);
	write_matrix(orientation, 3, 0, 0.0);
	write_matrix(orientation, 3, 1, 0.0);
	write_matrix(orientation, 3, 2, 0.0);
	write_matrix(orientation, 3, 3, 1.0);
}

t_matrix		view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_par9		p;
	t_matrix	orientation;
	t_matrix	t;
	t_matrix	resp;

	p.forward = normalize(sub(to, from));
	p.upn = normalize(up);
	p.left = cross(p.forward, p.upn);
	p.true_up = cross(p.left, p.forward);
	orientation = matrix(4);
	f_aux(&orientation, p);
	t = translation(-from.x, -from.y, -from.z);
	resp = matrix_multi(orientation, t);
	free_matrix(&orientation);
	free_matrix(&t);
	return (resp);
}
