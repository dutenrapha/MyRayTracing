/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 01:02:23 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 01:02:25 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_lights	*ft_lstnew_l(t_light content)
{
	t_lights	*new;

	if (!(new = (t_lights *)malloc(sizeof(t_lights))))
		return (NULL);
	if (new)
		new->content = content;
	new->next = NULL;
	return (new);
}
