/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_cv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 01:01:43 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 01:01:44 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_cv	*ft_lstnew_cv(t_canvas cv)
{
	t_cv	*new;

	if (!(new = (t_cv *)malloc(sizeof(t_cv))))
		return (NULL);
	if (new)
		new->content = cv;
	new->next = NULL;
	return (new);
}
