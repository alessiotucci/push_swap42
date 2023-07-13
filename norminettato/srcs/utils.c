/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:57:17 by atucci            #+#    #+#             */
/*   Updated: 2023/06/26 17:55:58 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus/libft.h"
#include "../incl/push_swap.h"
#include <stdint.h>
#include <limits.h>

void	swap(t_stack *a, t_stack *b)
{
	int	temp;

	temp = a->nbr;
	a->nbr = b->nbr;
	b->nbr = temp;
}

int	find_small(t_stack **stack_a, int *pos)
{
	int		small;
	t_stack	*current_node;

	*pos = 0;
	small = (*stack_a)->nbr;
	current_node = *stack_a;
	while (current_node != NULL)
	{
		if (current_node->nbr < small)
		{
			small = current_node->nbr;
			*pos = current_node->index;
		}
		current_node = current_node->next;
	}
	return (small);
}

int	free_split(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
	{
		free(tab[count++]);
	}
	free(tab);
	return (0);
}

int	update_indexes_and_get_length(t_stack *head)
{
	int		count;
	t_stack	*node;

	count = 0;
	node = head;
	while (node != NULL)
	{
		node->index = count;
		node = node->next;
		count++;
	}
	return (count);
}

long	ft_atoi_plus(const char *s)
{
	long	num;
	long	sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
		sign = -1;
	i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = (num * 10) + (s[i] - '0');
		i++;
	}
	if ((sign * num) > INT_MAX || (sign * num) < INT_MIN)
		return (print_exit());
	return (sign * num);
}
