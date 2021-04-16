/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_w.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 01:04:36 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 01:04:40 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_objects	*ft_lstnew_w(t_object content)
{
	t_objects	*new;

	if (!(new = (t_objects *)malloc(sizeof(t_objects))))
		return (NULL);
	if (new)
		new->content = content;
	new->next = NULL;
	return (new);
}
