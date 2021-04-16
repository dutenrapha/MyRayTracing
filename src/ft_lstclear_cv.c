/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_cv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 00:56:49 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 00:57:04 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	ft_lstclear_cv(t_cv **cv)
{
	t_cv	*current;
	t_cv	*next;

	current = *cv;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*cv = NULL;
}
