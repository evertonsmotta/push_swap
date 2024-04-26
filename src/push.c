/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:34:14 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/04 14:44:09 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (!b)
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
		stack_free(a);
		stack_free(b);
	}
	if (b->size >= 1)
	{
		stack_push(a, b);
		ft_putstr_fd("pa\n", 1);
	}
	else
	{
		stack_push(a, b);
		ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_stack *b, t_stack *a)
{
	if (!a)
		usage(ERR, a, b);
	else
	{
		stack_push(b, a);
		ft_putstr_fd("pb\n", 1);
	}
}
