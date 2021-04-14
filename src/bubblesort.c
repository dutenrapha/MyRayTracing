/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:50:22 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/14 19:59:36 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static	t_list	*swap(t_list *ptr1, t_list *ptr2)
{
	t_list	*tmp;

	tmp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tmp;
	return (ptr2);
}

void			bubblesort(t_list **xs)
{
	t_list	**temp;
	t_list	*p1;
	t_list	*p2;
	t_iter	p;

	init_iter(&p, *xs);
	while (++p.i < p.n)
	{
		p.j = -1;
		temp = xs;
		p.swapped = 0;
		while (++p.j < p.n - 1)
		{
			p1 = *temp;
			p2 = (*temp)->next;
			if (p1->content.t > p2->content.t)
			{
				*temp = swap(p1, p2);
				p.swapped = 1;
			}
			temp = &(*temp)->next;
		}
		if (p.swapped == 0)
			break ;
	}
}
