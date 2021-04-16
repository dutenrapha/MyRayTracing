/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 01:02:03 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 01:02:04 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_imgg	*ft_lstnew_img(t_data img)
{
	t_imgg	*new;

	if (!(new = (t_imgg *)malloc(sizeof(t_imgg))))
		return (NULL);
	if (new)
		new->content = img;
	new->next = NULL;
	return (new);
}
