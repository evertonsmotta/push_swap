/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:35:47 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/04 14:25:49 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large(t_stack *a, t_stack *b)
{
	int	i;
	int	min;
	int	j;
	int	l;
	int	*mingroup;

	min = get_min(a->begin, a->size);
	j = (a->size / 100) - 1;
	l = -1;
	i = 0;
	mingroup = malloc((j + 2) * sizeof(int));
	if (!mingroup)
		usage(ERR, a, b);
	while (++l < j)
	{
		mingroup[l] = get_mingroup(a->begin, i += 100, min, a->size);
	}
	l--;
	if (a->size >= 200)
		sort_large_500(a, b, l, mingroup);
	else
		sort_large_100(a, b, a->size);
	free(mingroup);
}
