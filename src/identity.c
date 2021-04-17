/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 03:02:24 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 03:04:30 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_matrix	identity(void)
{
	t_matrix a;

	a = matrix(4);
	writeMatrix(&a, 0, 0, 1.0);
	writeMatrix(&a, 0, 1, 0.0);
	writeMatrix(&a, 0, 2, 0.0);
	writeMatrix(&a, 0, 3, 0.0);
	writeMatrix(&a, 1, 0, 0.0);
	writeMatrix(&a, 1, 1, 1.0);
	writeMatrix(&a, 1, 2, 0.0);
	writeMatrix(&a, 1, 3, 0.0);
	writeMatrix(&a, 2, 0, 0.0);
	writeMatrix(&a, 2, 1, 0.0);
	writeMatrix(&a, 2, 2, 1.0);
	writeMatrix(&a, 2, 3, 0.0);
	writeMatrix(&a, 3, 0, 0.0);
	writeMatrix(&a, 3, 1, 0.0);
	writeMatrix(&a, 3, 2, 0.0);
	writeMatrix(&a, 3, 3, 1.0);
	return (a);
}
