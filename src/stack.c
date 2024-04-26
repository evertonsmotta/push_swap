/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:34:58 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/04 14:29:22 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_create(int val)
{
	t_node	*node;

	node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!node)
		exit (EXIT_FAILURE);
	node->val = val;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*stack_create(t_stack *stack)
{
	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stack)
		exit (EXIT_FAILURE);
	stack->begin = NULL;
	stack->end = NULL;
	stack->size = 0;
	return (stack);
}

void	stack_free(t_stack *stack_src)
{
	t_stack	*stack_aux;
	t_node	*node;
	t_node	*aux;

	stack_aux = stack_src;
	node = stack_aux->begin;
	aux = NULL;
	while (node != NULL)
	{
		aux = node;
		node = node->next;
		free(aux);
	}
	free(stack_aux);
	stack_src = NULL;
}

bool	stack_is_empty(const t_stack *stack)
{
	return (stack->size == 0);
}

void	node_remove(t_stack *stack, int val)
{
	t_node	*prev;
	t_node	*pos;

	if (!stack_is_empty(stack))
	{
		prev = NULL;
		pos = stack->begin;
		while (pos != NULL && pos->val != val)
		{
			prev = pos;
			pos = pos->next;
		}
		if (pos != NULL)
		{
			if (stack->end == pos)
				stack->end = prev;
			if (stack->begin == pos)
				stack->begin = stack->begin->next;
			else
				prev->next = pos->next;
			free(pos);
			stack->size--;
		}
	}
}
