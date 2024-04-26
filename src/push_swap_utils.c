/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:33:36 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/04 14:34:19 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return ((long)res * sign);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot_size;
	void	*dst;

	tot_size = size * count;
	dst = malloc(tot_size);
	if (!dst)
		return (0);
	ft_memset(dst, 0, tot_size);
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = b;
	i = 0;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}

// void	t_stack_print(const t_stack *stack)
// {
// 	t_node	*p;

// 	p = stack->begin;
// 	while (p != NULL)
// 	{
// 		printf("%d ", p->val);
// 		p = p->next;
// 	}
// 	if (stack->end == NULL && stack->begin == NULL)
// 	{
// 		printf("\nStack->begin = NULL\n");
// 		printf("Stack->end = NULL\n");
// 	}
// 	else
// 	{
// 		printf("\n\nStack->beg = %d\n", stack->begin->val);
// 		printf("Stack->end = %d\n", stack->end->val);
// 	}
// 	printf("\nStack->size: %d\n", stack->size);
// 	puts("");
// }

// void	print_stack(t_stack *stack)
// {
// 	t_node	*temp;

// 	temp = stack->begin;
// 	if (stack->begin == NULL)
// 	{
// 		printf("\n\nbegin: NULL ");
// 		printf("\nend: NULL ");
// 		printf("\nsize: 0 \n");
// 	}
// 	else
// 	{
// 		printf("\n\nbegin: %d ", stack->begin->val);
// 		printf("\nend: %d ", stack->end->val);
// 		printf("\nsize: %d \n", stack->size);
// 	}
// 	printf("\n");
// 	while (temp)
// 	{
// 		printf("%d ", temp->val);
// 		temp = temp->next;
// 	}
// 	printf("\n\n");
// }
