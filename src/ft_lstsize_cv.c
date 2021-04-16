/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_cv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 01:06:24 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 01:06:25 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	ft_lstsize_cv(t_cv *cv)
{
	int		i;
	t_cv	*temp;

	if (cv)
	{
		i = 1;
		temp = cv;
		while (temp->next)
		{
			temp = temp->next;
			i++;
		}
		return (i);
	}
	else
		return (0);
}
