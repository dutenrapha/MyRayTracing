/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:26:36 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/24 13:34:48 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(uintmax_t nb, char *base)
{
	int			cont_num;
	uintmax_t	base_len;
	uintmax_t	aux;
	char		*str;

	base_len = ft_strlen(base);
	cont_num = 1;
	aux = nb;
	str = NULL;
	while ((aux = aux / base_len) > 0)
		cont_num++;
	str = (char *)ft_calloc((cont_num + 1), sizeof(char));
	if (!str)
		return (NULL);
	cont_num--;
	while (cont_num >= 0)
	{
		str[cont_num] = base[nb % base_len];
		nb = nb / base_len;
		cont_num--;
	}
	return (str);
}
