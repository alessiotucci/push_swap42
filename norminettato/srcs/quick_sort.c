/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:24:26 by atucci            #+#    #+#             */
/*   Updated: 2023/06/26 17:55:37 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"
#include "../libft_plus/libft.h"

t_stack	*list_copy(t_stack **stack_a)
{
	t_stack	*new_list;
	t_stack	*current;
	t_stack	*new_node;
	t_stack	*temp;

	new_list = NULL;
	current = *stack_a;
	while (current != NULL)
	{
		new_node = add_new_nody(current->nbr, current->index);
		if (new_node == NULL)
		{
			while (new_list != NULL)
			{
				temp = new_list;
				new_list = new_list->next;
				free(temp);
			}
			return (NULL);
		}
		add_node_to_stack(&new_list, new_node);
		current = current->next;
	}
	return (new_list);
}

void	sort_the_list(t_stack **head)
{
	int		swapped;
	t_stack	*current;
	t_stack	*tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tail = NULL;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = *head;
		while (current->next != tail)
		{
			if (current->nbr > current->next->nbr)
			{
				swap(current, current->next);
				swapped = 1;
			}
			current = current->next;
		}
		tail = current;
	}
}

void	check_and_push(t_stack **stack_a, t_stack **stack_b, int middle)
{
	int	len_a;
	int	len_b;
	int	count;

	count = -1;
	len_a = get_list_length(*stack_a);
	len_b = 0;
	while ((len_a > len_b) && count < len_b)
	{
		if ((*stack_a)->index == 0 && (*stack_a)->nbr < middle)
			pb(stack_a, stack_b, 0);
		else
		{
			ra(stack_a, 0);
			count++;
		}
		update_indexes(*stack_b);
		len_b = get_list_length(*stack_b);
		update_indexes(*stack_a);
		len_a = get_list_length(*stack_a);
	}
	return ;
}

void	quick_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		middle;
	int		len_a;
	t_stack	*copy;

	len_a = get_list_length(*stack_a);
	copy = list_copy(stack_a);
	sort_the_list(&copy);
	if (len_a > 25)
		middle = get_medd_value(copy);
	else
		middle = get_mid_value(copy);
	check_and_push(stack_a, stack_b, middle);
	if (len_a == 2)
	{
		sort_due(stack_a);
		selection_sort_stack_b(stack_a, stack_b);
	}
	else
		quick_sort(stack_a, stack_b);
	free_lists(copy, *stack_b);
	return ;
}

void	selection_sort_stack_b(t_stack **a, t_stack **stack_b)
{
	int	pos;
	int	count;
	int	biggest_pos;
	int	moves;

	while (*stack_b != NULL)
	{
		biggest_pos = find_big(stack_b, &pos);
		moves = get_moves_to_top(*stack_b, pos);
		count = -1;
		while (++count < moves)
		{
			if (pos <= get_list_length(*stack_b) / 2)
				rb(stack_b, 0);
			else
				rrb(stack_b, 0);
			update_indexes(*stack_b);
		}
		pa(a, stack_b, 0);
		update_indexes(*a);
		update_indexes(*stack_b);
		if (*a && (*a)->next && (*a)->nbr > (*a)->next->nbr)
			sa(a, 0);
	}
	return ;
}
