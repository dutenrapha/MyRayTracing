/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeMatrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:47:32 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/14 20:48:28 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	free_matrix(t_matrix *a)
{
	int	i;

	i = 0;
	while (i < a->dim)
	{
		free(a->element[i]);
		i++;
	}
	free(a->element);
}
