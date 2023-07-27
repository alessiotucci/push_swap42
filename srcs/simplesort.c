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

/*
** Sorts two elements in ascending order if the stack is not already sorted.
** If the stack has only two elements and they are not sorted, it swaps them.
** This function is used when there are only two elements in the stack.
** It makes sure that the two elements are in ascending order after sorting.
** The 'sa' operation swaps the top two elements of the stack.
*/
void	sort_due(t_stack **stack_a)
{
	if (is_sorted(*stack_a) == 0)
		sa(stack_a, 0); // Swap the top two elements of stack_a.
	update_indexes(*stack_a); // Update the indexes of the stack after sorting.
	return ;
}

/*
** Sorts three elements in ascending order if the stack is not already sorted.
** If the stack has only three elements and they are not sorted, it performs
** a sequence of swap operations to sort the elements in ascending order.
** This function is used when there are only three elements in the stack.
** It ensures that the three elements are in ascending order after sorting.
*/
void	sort_tre(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ; // If the stack has less than three elements, no sorting is needed.

	a = (*stack_a)->nbr;
	b = (*stack_a)->next->nbr;
	c = (*stack_a)->next->next->nbr;
	while (!(a < b && b < c)) // Loop until the elements are in ascending order.
	{
		// Perform swap and rotation operations to sort the three elements.
		if (b < a && a < c)
			sa(stack_a, 0); // Swap the top two elements of stack_a.
		else if (c < b && b < a)
			sa(stack_a, 0); // Swap the top two elements of stack_a.
		else if (a < c && c < b)
			rra(stack_a, 0); // Rotate stack_a counter-clockwise.
		else if (b < c && c < a)
			ra(stack_a, 0); // Rotate stack_a clockwise.
		else if (c < a && a < b)
			rra(stack_a, 0); // Rotate stack_a counter-clockwise.

		a = (*stack_a)->nbr; // Update the values of a, b, and c.
		b = (*stack_a)->next->nbr;
		c = (*stack_a)->next->next->nbr;
	}
}

/*
** Creates a new stack node with the given 'number' and 'index'.
** Allocates memory for the new node and initializes its 'nbr', 'index',
** 'next', and 'prev' fields. Returns the pointer to the new node.
*/
t_stack	*create_new_node(char *number, int index)
{
	t_stack	*new_node; // Pointer to the new stack node.

	new_node = (t_stack *)malloc(sizeof(t_stack)); // Allocate memory for the new node.
	if (!new_node)
		return (NULL); // Return NULL if memory allocation fails.

	new_node->nbr = ft_atoi(number); // Convert the 'number' string to an integer and assign it to the 'nbr' field.
	new_node->index = index; // Assign the 'index' value to the 'index' field.
	new_node->next = NULL; // Set the 'next' pointer to NULL as this is a new node.
	new_node->prev = NULL; // Set the 'prev' pointer to NULL as this is a new node.

	return (new_node); // Return the pointer to the new stack node.
}

/*
** Adds a new node to the end of the stack.
** If the stack is empty, the new node becomes the head of the stack.
** If the stack is not empty, the new node is appended to the end of the stack.
*/
void	add_node_to_stack(t_stack **stack, t_stack *new_node)
{
	t_stack	*last_node; // Pointer to the last node of the stack.

	if (!*stack)
	{
		*stack = new_node; // If the stack is empty, the new node becomes the head of the stack.
		return ;
	}

	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next; // Traverse to the last node of the stack.

	last_node->next = new_node; // Append the new node to the end of the stack.
	new_node->prev = last_node; // Set the 'prev' pointer of the new node to the previous last node.
}

/*
** Sets the index of the new_node based on the index of the previous node in the stack.
** If the stack is not empty, it sets the 'index' field of the new node to the 'index' value
** of the previous node plus one. If the stack is empty, the 'index' of the new node is set to 0.
*/
void	set_index(t_stack **new_node, t_stack *stack)
{
	if (stack != NULL)
		(*new_node)->index = stack->index++; // Set the 'index' of the new node to the 'index' value of the previous node plus one.
	else
		(*new_node)->index = 0; // If the stack is empty, set the 'index' of the new node to 0.
}
