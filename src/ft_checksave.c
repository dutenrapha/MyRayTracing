/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksave.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 00:36:10 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 00:36:25 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

bool	ft_checksave(int argc)
{
	bool	resp;

	resp = false;
	if (argc == 3)
	{
		resp = true;
	}
	return (resp);
}
