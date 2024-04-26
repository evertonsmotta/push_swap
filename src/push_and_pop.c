/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:32:46 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/04 14:30:05 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_push(t_stack *stack, int val)
{
	t_node	*node;

	node = node_create(val);
	node->next = stack->begin;
	if (stack_is_empty(stack))
		stack->end = node;
	stack->begin = node;
	stack->size++;
}

void	stack_push(t_stack *stack_dest, t_stack *stack_src)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		usage(ERR, stack_dest, stack_src);
	node->val = stack_src->begin->val;
	node->next = stack_dest->begin;
	if (stack_dest->begin == NULL)
		stack_dest->end = node;
	stack_dest->begin = node;
	stack_dest->size++;
	stack_pop(stack_src);
}

void	stack_pop(t_stack *stack)
{
	t_node	*beg;

	if (!stack || !stack->begin)
		exit (EXIT_FAILURE);
	beg = stack->begin;
	stack->begin = beg->next;
	stack->size--;
	if (stack->size == 0)
		stack->end = NULL;
	free(beg);
}

void	push_end(t_stack *stack, int val)
{
	t_node	*q;

	q = node_create(val);
	if (stack_is_empty(stack))
	{
		stack->begin = q;
		stack->end = q;
	}
	else
	{
		stack->end->next = q;
		stack->end = stack->end->next;
	}
	stack->size++;
}
