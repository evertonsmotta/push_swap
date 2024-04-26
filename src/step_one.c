/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:35:24 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/04 14:25:18 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large_100_a(t_stack *a, t_stack *b, int *mingroup, int j)
{
	int	size;
	int	min;

	min = get_min(a->begin, a->size);
	size = 100;
	if (a->size < 200)
		size = a->size;
	if (b->size == 0)
		first_step(a, b, mingroup);
	if (j < 200)
		second_step(a, b, mingroup, size);
	else
		second_step_big(a, b, mingroup, 100);
	if (j < 200)
		third_step(a, b);
	else
		while (!is_sorted(a))
			pb(b, a);
	fourth_step(a, b, j, min);
	if (b->size == 2)
		last_step(a, b);
}

void	sort_large_100(t_stack *a, t_stack *b, int j)
{
	int	i;
	int	l;
	int	size;
	int	*mingroup;
	int	min;

	i = 1;
	l = -1;
	size = 100;
	if (a->size < 200)
		size = a->size;
	min = get_min(a->begin, a->size);
	mingroup = malloc(10 * sizeof(int));
	if (!mingroup)
		usage(ERR, a, b);
	while (++l < 8)
	{
		mingroup[l] = get_mingroup(a->begin, size / 10 * i, min, size);
		i++;
	}
	mingroup[8] = min;
	sort_large_100_a(a, b, mingroup, j);
	free(mingroup);
}

void	sort_large_500_b(t_stack *a, t_stack *b, int i, int mingroup)
{
	while (a->size < i)
	{
		if (b->begin->val <= mingroup)
			pa(a, b);
		else
			rb(b);
	}
	sort_large_100(a, b, i);
}

void	sort_large_500_a(t_stack *a, t_stack *b, int l, int *mingroup)
{
	int	i;

	i = mingroup[l];
	while (b->size != 0 && l--)
	{
		while (a->size < i)
		{
			if (b->begin->val >= mingroup[l])
				pa(a, b);
			else
				rb(b);
		}
		sort_large_100(a, b, i);
		i += 100;
		if (b->size == 100)
			sort_large_500_b(a, b, i, mingroup[l]);
	}
}

void	sort_large_500(t_stack *a, t_stack *b, int l, int *mingroup)
{
	int	i;

	i = 100;
	if (a->size % 100 != 0)
		i = 100 + (a->size % 100);
	while (a->size > i)
	{
		if (a->begin->val < mingroup[l])
			pb(b, a);
		else
			ra(a);
	}
	sort_large_100(a, b, i);
	i += 100;
	if (b->size == 100)
		sort_large_500_b(a, b, i, mingroup[l]);
	else
	{
		mingroup[l] = i;
		sort_large_500_a(a, b, l, mingroup);
	}
}
