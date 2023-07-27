/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:04:35 by atucci            #+#    #+#             */
/*   Updated: 2023/07/27 18:49:15 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"
#include "../libft_plus/libft.h"

/*
** Calculate the mid value of the stack based on the number of nodes in the list.
** It divides the length of the list by 2 to find the mid_index.
** Then, it traverses the list to find the node at the mid_index position.
** Returns the value (nbr) of the node at the mid_index.
*/
int	get_mid_value(t_stack *head)
{
	int		len;        // Variable to store the length of the list.
	int		mid_index;  // Variable to store the index of the middle element.
	t_stack	*current;   // Pointer to traverse the list.
	int		i;          // Counter variable.

	len = get_list_length(head); // Get the length of the list.
	mid_index = len / 2;         // Calculate the mid_index by dividing the length by 2.

	current = head;
	i = 0;
	while (i < mid_index)
	{
		current = current->next; // Traverse the list to the middle element.
		i++;
	}

	return (current->nbr); // Return the value of the middle element.
}

/*
** Calculate the median value of the stack based on the number of nodes in the list.
** It divides the length of the list by 6 to find the mid_index.
** Then, it traverses the list to find the node at the mid_index position.
** Returns the value (nbr) of the node at the mid_index.
*/
int	get_medd_value(t_stack *head)
{
	int		len;        // Variable to store the length of the list.
	int		mid_index;  // Variable to store the index of the middle element.
	t_stack	*current;   // Pointer to traverse the list.
	int		i;          // Counter variable.

	len = get_list_length(head); // Get the length of the list.
	mid_index = len / 6;         // Calculate the mid_index by dividing the length by 6.

	current = head;
	i = 0;
	while (i < mid_index)
	{
		current = current->next; // Traverse the list to the middle element.
		i++;
	}

	return (current->nbr); // Return the value of the middle element.
}

/*
** Create a new node for the stack with the given number and index.
** It allocates memory for the new node, sets its 'nbr' and 'index' fields,
** and initializes the 'next' and 'prev' pointers to NULL.
** Returns a pointer to the newly created node.
** If memory allocation fails, it returns NULL.
*/
t_stack	*add_new_nody(int number, int index)
{
	t_stack	*new_node; // Pointer to the new node.

	new_node = malloc(sizeof(t_stack)); // Allocate memory for the new node.
	if (!new_node) // Check if memory allocation was successful.
		return (NULL); // If not, return NULL.

	// Initialize the fields of the new node.
	new_node->nbr = number;
	new_node->index = index;
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node); // Return the pointer to the new node.
}

/*
** Free the memory allocated for two linked lists, list_a and list_b.
** It traverses list_a and list_b, freeing each node's memory as it goes.
** If list_b is NULL, it means only list_a needs to be freed.
** Returns 1 if only list_a is freed, 2 if both list_a and list_b are freed.
*/
int	free_lists(t_stack *list_a, t_stack *list_b)
{
	t_stack	*temp;

	while (list_a != NULL)
	{
		temp = list_a;
		list_a = list_a->next;
		free(temp); // Free the memory of the current node in list_a.
	}

	if (list_b == NULL)
		return (1); // Return 1 if only list_a is freed.

	while (list_b != NULL)
	{
		temp = list_b;
		list_b = list_b->next;
		free(temp); // Free the memory of the current node in list_b.
	}

	return (2); // Return 2 if both list_a and list_b are freed.
}

/*
** Process the elements in stack_b during sorting.
** It updates the indexes of both stack_a and stack_b.
** If stack_a has only three elements, it sorts those elements directly.
** Then, it moves all elements from stack_b back to stack_a (using 'pa' operation).
*/
void	process_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	update_indexes(*stack_b); // Update the indexes of stack_b.
	update_indexes(*stack_a); // Update the indexes of stack_a.

	// If stack_a has only three elements, sort them directly.
	if (get_list_length(*stack_a) == 3)
		sort_tre(stack_a);

	// Move all elements from stack_b back to stack_a using 'pa' operation.
	while (*stack_b != NULL)
		pa(stack_a, stack_b, 0);

	update_indexes(*stack_a); // Update the indexes of stack_a again after the 'pa' operations.
}
