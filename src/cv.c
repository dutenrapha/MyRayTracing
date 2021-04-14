/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:38:46 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/14 20:39:39 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	cv(t_cv **l, t_canvas cv)
{
	t_cv *temp;

	if (ft_lstsize_cv(*l) == 0)
	{
		*l = ft_lstnew_cv(cv);
	}
	else
	{
		temp = *l;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = ft_lstnew_cv(cv);
	}
}
