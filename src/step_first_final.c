/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_first_final.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:35:06 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/03 14:50:53 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_step(t_stack *a, t_stack *b, int	*ming)
{
	int	maxa;

	maxa = get_max(a->begin, a->size);
	while (!is_sorted(a) && b->size < 2)
	{
		maxa = get_max(a->begin, a->size);
		if (a->begin->val < ming[1])
			pb(b, a);
		else if (a->begin->val == maxa)
			ra(a);
		else if (a->begin->val > a->begin->next->val)
			sa(a);
		else
			ra(a);
	}
	if (a->size >= 200)
		while (a->end->val != maxa)
			rra(a);
}

void	last_step_a(t_stack *a, t_stack *b)
{
	if (a->begin->val > a->begin->next->val)
		sa(a);
	else if (a->end->val < a->begin->val
		&& a->end->val > b->begin->val)
		rra(a);
	else
		pa(a, b);
}

void	last_step(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		if (b->size > 1)
		{
			if (a->begin->val > a->begin->next->val
				&& b->begin->val < b->begin->next->val)
				ss(a, b);
			else if (a->begin->val > a->begin->next->val)
				sa(a);
			else if (b->begin->val < b->begin->next->val)
				sb(b);
			else if (a->end->val < a->begin->val
				&& a->end->val > b->begin->val)
				rra(a);
			else
				pa(a, b);
		}
		else
			last_step_a(a, b);
	}
}
