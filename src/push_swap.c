/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:34:01 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/07 10:06:31 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	usage(char *msg, t_stack *a, t_stack *b)
{
	int	fd;

	fd = 1;
	ft_putstr_fd(msg, fd);
	write(1, "\n", 1);
	stack_free(a);
	stack_free(b);
	exit(EXIT_FAILURE);
}

static int	ft_is_valid_number(char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	while (*s >= '0' && *s <= '9')
		s++;
	if (*s && !(*s >= '0' && *s <= '9'))
		return (0);
	if (!*s && (*(s - 1) == '+' || *(s - 1) == '-'))
		return (0);
	return (1);
}

t_stack	*check_initial(int argc, char **argv, t_stack *a, t_stack *b)
{
	long int	temp;
	int			val;

	while (argc && argc > 1)
	{
		if (ft_is_valid_number(argv[argc - 1]) == 0)
			usage(ERR, a, b);
		temp = atol(argv[argc -1]);
		if (temp > INT_MAX || temp < INT_MIN)
			usage(ERR, a, b);
		val = (int)temp;
		first_push(a, val);
		argc--;
	}
	if (is_double(a) == 1)
		usage(ERR, a, b);
	return (a);
}

bool	is_sorted(t_stack *stk)
{
	t_node	*naux;

	naux = stk->begin;
	if (!stk)
		return (false);
	while (naux != stk->end)
	{
		if (naux->val > naux->next->val)
			return (false);
		naux = naux->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	a = stack_create(a);
	b = stack_create(b);
	if (argc == 2 && ft_is_valid_number(argv[argc - 1]) == 0)
		usage(ERR, a, b);
	a = check_initial(argc, argv, a, b);
	if (!is_sorted(a))
	{
		if (a->size < 4 && a->size > 2)
			sort_small(a);
		else if (a->size < 6 && a->size > 3)
			sort_medium(a, b);
		else
			sort_large(a, b);
	}
	stack_free(a);
	stack_free(b);
	return (0);
}
