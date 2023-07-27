/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:37:20 by atucci            #+#    #+#             */
/*   Updated: 2023/07/27 18:45:33 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Including necessary header files
#include "../libft_plus/libft.h"
#include "../incl/push_swap.h"

/*
** Updates the index values of nodes in the linked list.
** Each node's index represents its position in the list (0-based index).
** The first node in the list will have an index of 0, the second node will have 1, and so on.
** This function traverses the list and assigns the correct index values to each node.
** The input parameter 'list1' is the head node of the linked list.
*/
void	update_indexes(t_stack *list1)
{
	int		i;        // Counter variable to keep track of the current index.
	t_stack	*node;    // Pointer to traverse the linked list.

	i = 0;             // Initialize the counter to 0.
	node = list1;      // Start traversing from the head node of the list.

	// Loop through the linked list until the end (NULL node) is reached.
	while (node != NULL)
	{
		node->index = i;  // Assign the current index value to the 'index' field of the current node.
		node = node->next; // Move to the next node in the list.
		i++;              // Increment the counter to move to the next index.
	}
}

void	pa(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (j == 0)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int j)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	if (j == 0)
		write(1, "pb\n", 3);
}

void	sa(t_stack **a, int j)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (j == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (j == 0)
		write(1, "sb\n", 3);
}


