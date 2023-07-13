/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:04:35 by atucci            #+#    #+#             */
/*   Updated: 2023/06/26 17:55:31 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"
#include "../libft_plus/libft.h"

int	get_mid_value(t_stack *head)
{
	int		len;
	int		mid_index;
	t_stack	*current;
	int		i;

	len = get_list_length(head);
	mid_index = len / 2;
	current = head;
	i = 0;
	while (i < mid_index)
	{
		current = current->next;
		i++;
	}
	return (current->nbr);
}

int	get_medd_value(t_stack *head)
{
	int		len;
	int		mid_index;
	t_stack	*current;
	int		i;

	len = get_list_length(head);
	mid_index = len / 6;
	current = head;
	i = 0;
	while (i < mid_index)
	{
		current = current->next;
		i++;
	}
	return (current->nbr);
}

t_stack	*add_new_nody(int number, int index)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->nbr = number;
	new_node->index = index;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

int	free_lists(t_stack *list_a, t_stack *list_b)
{
	t_stack	*temp;

	while (list_a != NULL)
	{
		temp = list_a;
		list_a = list_a->next;
		free(temp);
	}
	if (list_b == NULL)
		return (1);
	while (list_b != NULL)
	{
		temp = list_b;
		list_b = list_b->next;
		free(temp);
	}
	return (2);
}

void	process_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	update_indexes(*stack_b);
	update_indexes(*stack_a);
	if (get_list_length(*stack_a) == 3)
		sort_tre(stack_a);
	while (*stack_b != NULL)
		pa(stack_a, stack_b, 0);
	update_indexes(*stack_a);
}
