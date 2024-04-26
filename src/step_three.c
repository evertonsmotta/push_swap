/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:35:31 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/01 15:19:15 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	second_step_big_a(t_stack *a, t_stack *b, int *ming, int l)
{
	if ((b->begin->val < b->end->val) && (b->size == 2))
		rb(b);
	else if (a->begin->val < ming[l + 1])
		second_step_a(a, b, ming, l);
	else
		second_step_b(a, b, ming);
}

void	second_step_big_b(t_stack *a, t_stack *b, int *ming, int l)
{
	if ((b->begin->val < b->end->val) && (b->size == 2))
		rb(b);
	else if (a->begin->val < ming[l + 1])
		second_step_a_rev(a, b, ming, l);
	else
		second_step_b_rev(a, b, ming);
}

void	second_step_big(t_stack *a, t_stack *b, int *ming, int j)
{
	int	l;
	int	maxa;
	int	maxlist_a;

	maxlist_a = get_max(a->begin, a->size);
	maxa = get_max(a->begin, j);
	l = 0;
	while (l < 8)
	{
		while (a->begin->val <= maxa)
			second_step_big_a(a, b, ming, l);
		l = l + 2;
		while (a->end->val != maxlist_a)
			second_step_big_b(a, b, ming, l);
		l = l + 2;
	}
}
