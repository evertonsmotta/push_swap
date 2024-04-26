/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:34:43 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/01 15:30:15 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_medium(t_stack *a, t_stack *b)
{
	while (a->size > 3 && a->size < 6)
	{
		if (a->begin->val == get_min(a->begin, a->size))
			pb(b, a);
		else if (a->begin->next->val == get_min(a->begin, a->size))
		{
			sa(a);
			pb(b, a);
		}
		else if (a->end->val == get_min(a->begin, a->size))
		{
			rra(a);
			pb(b, a);
		}
		else
			rra(a);
	}
	if (a->size == 3)
	{
		sort_small(a);
		while (b != NULL && b->size != 0)
			pa(a, b);
	}
}
