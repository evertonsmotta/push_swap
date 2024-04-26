/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:35:56 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/04 14:28:15 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*naux;

	if (stack->size == 2)
	{
		naux = stack->begin;
		stack->begin = stack->begin->next;
		stack->end->next = naux;
		naux->next = NULL;
		stack->end = naux;
	}
	else
	{
		naux = stack->begin;
		stack->begin = stack->begin->next;
		naux->next = stack->begin->next;
		stack->begin->next = naux;
	}
}

void	sa(t_stack *stack)
{
	t_node	*naux;

	naux = stack->begin;
	stack->begin = stack->begin->next;
	naux->next = stack->begin->next;
	stack->begin->next = naux;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack)
{
	t_node	*naux;

	if (!stack)
		exit (EXIT_FAILURE);
	if (stack->size == 2)
	{
		naux = stack->begin;
		stack->begin = stack->begin->next;
		stack->end->next = naux;
		naux->next = NULL;
		stack->end = naux;
		ft_putstr_fd("sb\n", 1);
	}
	else
	{
		naux = stack->begin;
		stack->begin = stack->begin->next;
		naux->next = stack->begin->next;
		stack->begin->next = naux;
		ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
