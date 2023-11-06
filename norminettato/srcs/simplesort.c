/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:36:56 by atucci            #+#    #+#             */
/*   Updated: 2023/06/26 17:55:50 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus/libft.h"
#include "../incl/push_swap.h"

void	sort_due(t_stack **stack_a)
{
	if (is_sorted(*stack_a) == 0)
		sa(stack_a, 0);
	update_indexes(*stack_a);
	return ;
}

void	sort_tre(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	a = (*stack_a)->nbr;
	b = (*stack_a)->next->nbr;
	c = (*stack_a)->next->next->nbr;
	while (!(a < b && b < c))
	{
		if (b < a && a < c)
			sa(stack_a, 0);
		else if (c < b && b < a)
			sa(stack_a, 0);
		else if (a < c && c < b)
			rra(stack_a, 0);
		else if (b < c && c < a)
			ra(stack_a, 0);
		else if (c < a && a < b)
			rra(stack_a, 0);
		a = (*stack_a)->nbr;
		b = (*stack_a)->next->nbr;
		c = (*stack_a)->next->next->nbr;
	}
}

t_stack	*create_new_node(char *number, int index)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->nbr = ft_atoi(number);
	new_node->index = index;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	add_node_to_stack(t_stack **stack, t_stack *new_node)
{
	t_stack	*last_node;

	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = new_node;
	new_node->prev = last_node;
}

void	set_index(t_stack **new_node, t_stack *stack)
{
	if (stack != NULL)
		(*new_node)->index = stack->index++;
	else
		(*new_node)->index = 0;
}
