/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_img.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:22:08 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 01:22:39 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	n_img(t_imgg **l, t_data img)
{
	t_imgg	*temp;

	if (ft_lstsize_img(*l) == 0)
	{
		*l = ft_lstnew_img(img);
	}
	else
	{
		temp = *l;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = ft_lstnew_img(img);
	}
}
