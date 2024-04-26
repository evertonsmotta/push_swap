/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:35:06 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/01 15:19:31 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	third_step_a(t_stack *a, t_stack *b)
{
	if ((a->begin->val > a->begin->next->val)
		&& (b->begin->val < b->begin->next->val))
		ss(a, b);
	else if (a->begin->val > a->begin->next->val)
		sa(a);
	else
		sb(b);
}

void	third_step(t_stack *a, t_stack *b)
{
	while (!is_sorted(a))
	{
		if ((a->begin->val < a->begin->next->val)
			&& (a->begin->val < a->end->val))
			pb(b, a);
		else if ((a->begin->val > a->begin->next->val)
			&& (a->begin->next->val > a->end->val))
			sa(a);
		else if ((a->begin->val > a->end->val)
			&& (a->end->val > a->begin->next->val))
			ra(a);
		else if ((a->begin->val < a->begin->next->val)
			&& (a->begin->val > a->end->val))
			ra(a);
		else
			third_step_a(a, b);
	}
}

void	fourth_step_a(t_stack *a, t_stack *b, int mina)
{
	if (a->begin->val > a->begin->next->val)
		sa(a);
	else if ((b->begin->val < b->begin->next->val)
		&& (b->begin->val >= mina))
		sb(b);
	else if ((a->end->val < a->begin->val
			&& a->end->val > b->begin->val)
		&& (b->begin->val >= mina))
		rra(a);
	else if ((b->begin->val > a->begin->val
			&& b->begin->val > a->begin->next->val)
		&& (b->begin->val >= mina))
	{
		ra(a);
		ra(a);
	}
	else
		pa(a, b);
}

void	fourth_step(t_stack *a, t_stack *b, int j, int mina)
{
	while (a->size < j && b->size != 2)
	{
		if (b->end->val > b->begin->val)
			rrb(b);
		else if (((b->begin->val < b->begin->next->val)
				&& (a->begin->next->val > a->end->val)
				&& (a->begin->val > a->begin->next->val)
				&& (b->begin->val >= mina))
			|| ((b->begin->val < b->begin->next->val)
				&& (a->begin->val < a->end->val)
				&& (a->begin->val > a->begin->next->val)
				&& (b->begin->val >= mina)))
			ss(a, b);
		else
			fourth_step_a(a, b, mina);
	}
}
