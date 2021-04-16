/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 00:57:37 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 00:57:38 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	ft_lstclear_img(t_imgg **img)
{
	t_imgg	*current;
	t_imgg	*next;

	current = *img;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*img = NULL;
}
