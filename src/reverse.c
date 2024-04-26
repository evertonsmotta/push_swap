/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:34:26 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/01 14:44:29 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack *stack)
{
	t_node	*nindex;
	t_node	*nprev;

	if (!stack || !stack->begin->next)
		return ;
	nprev = NULL;
	nindex = stack->begin;
	while (nindex->next != NULL)
	{
		nprev = nindex;
		nindex = nindex->next;
	}
	nprev->next = NULL;
	nindex->next = stack->begin;
	stack->begin = nindex;
	stack->end = nprev;
}

void	rra(t_stack *stack)
{
	reverse(stack);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack)
{
	reverse(stack);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
