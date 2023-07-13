/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:18:35 by atucci            #+#    #+#             */
/*   Updated: 2023/06/26 17:55:43 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus/libft.h"
#include "../incl/push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		pos;
	int		nb;
	int		moves;
	int		count;
	int		conto;

	conto = update_indexes_and_get_length(*stack_a);
	while (conto > 3)
	{
		nb = find_small(stack_a, &pos);
		moves = get_moves_to_top(*stack_a, pos);
		count = -1;
		while (++count < moves)
		{
			if (pos <= get_list_length(*stack_a) / 2)
				ra(stack_a, 0);
			else
				rra(stack_a, 0);
			update_indexes(*stack_a);
		}
		pb(stack_a, stack_b, 0);
		conto = update_indexes_and_get_length(*stack_a);
	}
	process_stack_b(stack_a, stack_b);
}

int	is_sorted(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (current != NULL && current->next != NULL)
	{
		if (current->nbr > current->next->nbr)
			return (0);
	current = current->next;
	}
	return (1);
}

int	find_big(t_stack **stack_b, int *pos)
{
	int		big;
	t_stack	*current_node;

	*pos = 0;
	big = (*stack_b)->nbr;
	current_node = *stack_b;
	while (current_node != NULL)
	{
		if (current_node->nbr > big)
		{
			big = current_node->nbr;
			*pos = current_node->index;
		}
		current_node = current_node->next;
	}
	return (big);
}

int	get_moves_to_top(t_stack *stack, int index)
{
	int	size;
	int	moves;

	moves = 0;
	size = get_list_length(stack);
	if (index == 0)
		return (0);
	if (index <= size / 2)
		moves = index;
	else
		moves = size - index;
	return (moves);
}

int	is_empty(t_stack **stack)
{
	if ((*stack) == NULL)
		return (0);
	else
		return (1);
}
