/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:34:50 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/06/30 21:06:18 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *a)
{
	int	min;
	int	max;

	min = get_min(a->begin, a->size);
	max = get_max(a->begin, a->size);
	while (!is_sorted(a))
	{
		if (a->begin->val == max
			&& a->begin->next->val == min)
			ra(a);
		else if ((a->begin->val == min
				&& a->begin->next->val == max)
			|| (a->begin->val > a->begin->next->val))
			sa(a);
		else
			rra(a);
	}
}
