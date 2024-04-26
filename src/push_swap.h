/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:33:10 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/04 14:27:18 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX 2147483647
# define MIN -2147483648

/* Include my libraries */
# include "../libft/libft.h"
# include "usage.h"

/* Include external libraries */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdbool.h>

# include <sys/types.h>
# include <fcntl.h>
# include <stdarg.h>

/* Structure for linked list nodes */
typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				val;
}			t_node;

/* Structure for stack */
typedef struct s_stack
{
	t_node	*begin;
	t_node	*end;
	int		size;
}			t_stack;

void	usage(char *msg, t_stack *a, t_stack *b);
void	stack_free(t_stack *stack_src);
bool	stack_is_empty(const t_stack *L);
void	push_end(t_stack *stack, int val);
void	t_stack_print(const t_stack *stack);
void	print_stack(t_stack *stack);
void	first_push(t_stack *stack, int val);
void	stack_push(t_stack *stack_dest, t_stack *stack_src);
void	stack_pop(t_stack *stack);
void	node_remove(t_stack *L, int val);
int		is_double(t_stack *stack);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	swap(t_stack *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	reverse(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);
bool	is_sorted(t_stack *stk);
void	sort_small(t_stack *a);
int		get_mingroup(t_node *list, int size, int min, int sizelist);
int		get_min(t_node *list, int i);
int		get_max(t_node *list, int i);
void	sort_small(t_stack *a);
void	sort_medium(t_stack *stack_a, t_stack *stack_b);
void	*sortLast3(t_stack *stack_a, t_stack *stack_b);
void	sort_large(t_stack *a, t_stack *b);
void	first_step(t_stack *a, t_stack *b, int	*ming);
void	sort_large_100_a(t_stack *a, t_stack *b, int *mingroup, int j);
void	sort_large_100(t_stack *a, t_stack *b, int j);
void	sort_large_500_b(t_stack *a, t_stack *b, int i, int mingroup);
void	sort_large_500_a(t_stack *a, t_stack *b, int l, int *mingroup);
void	sort_large_500(t_stack *a, t_stack *b, int l, int *mingroup);
void	second_step_a(t_stack *a, t_stack *b, int *ming, int l);
void	second_step_a_rev(t_stack *a, t_stack *b, int	*ming, int l);
void	second_step_b(t_stack *a, t_stack *b, int *ming);
void	second_step_b_rev(t_stack *a, t_stack *b, int *ming);
void	second_step(t_stack *a, t_stack *b, int *ming, int size);
void	second_step_big_a(t_stack *a, t_stack *b, int *ming, int l);
void	second_step_big_b(t_stack *a, t_stack *b, int *ming, int l);
void	second_step_big(t_stack *a, t_stack *b, int *ming, int j);
void	third_step_a(t_stack *a, t_stack *b);
void	third_step(t_stack *a, t_stack *b);
void	fourth_step_a(t_stack *a, t_stack *b, int mina);
void	fourth_step(t_stack *a, t_stack *b, int j, int mina);
void	last_step_a(t_stack *a, t_stack *b);
void	last_step(t_stack *a, t_stack *b);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
long	ft_atol(const char *str);
t_node	*node_create(int val);
t_stack	*stack_create(t_stack *stack);

#endif
