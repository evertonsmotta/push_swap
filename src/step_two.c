/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:35:39 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/01 15:18:40 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	second_step_a(t_stack *a, t_stack *b, int *ming, int l)
{
	int	maxa;
	int	mina;

	mina = ming[8];
	pb(b, a);
	maxa = get_max(a->begin, a->size);
	if ((a->begin->val == maxa)
		&& (b->begin->val < b->end->val)
		&& (b->begin->val >= mina))
		rr(a, b);
	else if ((a->begin->val == maxa)
		&& (b->begin->val < b->end->val)
		&& (b->begin->val < ming[l]) && (b->begin->val >= mina))
		rr(a, b);
	else if ((b->begin->val < ming[l])
		&& (a->begin->val > ming[l + 1])
		&& (b->begin->val >= mina))
		rr(a, b);
	else if ((b->begin->val < b->end->val)
		&& (b->begin->val >= mina))
		rb(b);
	else if (b->begin->val < ming[l] && (b->begin->val >= mina))
		rb(b);
}

void	second_step_a_rev(t_stack *a, t_stack *b, int	*ming, int l)
{
	int	mina;

	mina = ming[8];
	pb(b, a);
	if ((b->begin->val < b->end->val)
		&& (b->begin->val >= mina))
		rb(b);
	else if (b->begin->val < ming[l]
		&& (b->begin->val >= mina))
		rb(b);
}

void	second_step_b(t_stack *a, t_stack *b, int *ming)
{
	int	maxa;
	int	mina;

	mina = ming[8];
	maxa = get_max(a->begin, a->size);
	if (a->begin->val == maxa)
		ra(a);
	else if ((a->begin->val > a->begin->next->val)
		&& (b->begin->val < b->begin->next->val)
		&& (b->begin->val >= mina))
		ss(a, b);
	else if (a->begin->val < a->begin->next->val)
		ra(a);
	else if ((b->begin->val < b->begin->next->val)
		&& (b->begin->val >= mina))
		sb(b);
	else
		ra(a);
}

void	second_step_b_rev(t_stack *a, t_stack *b, int *ming)
{
	int	mina;

	mina = ming[8];
	if ((b->begin->val < b->begin->next->val)
		&& (b->begin->val >= mina))
		sb(b);
	else
		rra(a);
}

void	second_step(t_stack *a, t_stack *b, int *ming, int size)
{
	int	i;
	int	l;
	int	j;

	j = 0;
	if (b->size == 2)
		j = 2;
	i = -1;
	l = 0;
	while (++i < 4)
	{
		while (j < (size / 10 * 2))
		{
			if (a->begin->val < ming[l + 1])
			{
				second_step_a(a, b, ming, l);
				j++;
			}
			else
				second_step_b(a, b, ming);
		}
		j = 0;
		l = l + 2;
	}
}
