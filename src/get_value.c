/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:32:27 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/03 16:44:49 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_node *list, int i)
{
	int	min;

	if (!list)
		return (EXIT_FAILURE);
	min = list->val;
	while (i > 0 && list)
	{
		if (list->val < min)
			min = list->val;
		list = list->next;
		i--;
	}
	return (min);
}

int	get_max(t_node *list, int i)
{
	int	max;

	if (!list)
		return (EXIT_FAILURE);
	max = list->val;
	while (i > 0 && list)
	{
		if (list->val > max)
			max = list->val;
		list = list->next;
		i--;
	}
	return (max);
}

int	get_mingroup(t_node *list, int size, int min, int sizelist)
{
	t_node	*temp;
	int		min2;
	int		j;

	j = sizelist;
	while (size-- > 0)
	{
		temp = list;
		while (temp->val <= min)
		{
			temp = temp->next;
			j--;
		}
		min2 = temp->val;
		while (j > 0)
		{
			if ((temp->val < min2) && (temp->val > min))
				min2 = temp->val;
			temp = temp->next;
			j--;
		}
		min = min2;
		j = sizelist;
	}
	return (min);
}

int	is_double(t_stack *stack)
{
	t_node	*check_double;
	t_node	*nindex;
	int		i;
	int		j;

	i = 1;
	j = 1;
	check_double = stack->begin;
	nindex = check_double->next;
	while (i < stack->size)
	{
		while (j++ < stack->size)
		{
			if (check_double->val == nindex->val)
				return (1);
			nindex = nindex->next;
		}
		check_double = check_double->next;
		if (check_double->next)
			nindex = check_double->next;
		i++;
		j = i;
	}
	return (0);
}
