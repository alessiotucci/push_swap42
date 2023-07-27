/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:24:26 by atucci            #+#    #+#             */
/*   Updated: 2023/07/27 18:52:56 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"
#include "../libft_plus/libft.h"
/*
** Creates a copy of the given linked list 'stack_a'.
** It copies the elements of 'stack_a' to a new list 'new_list'.
** Returns a pointer to the new list (the copied list).
** If memory allocation fails, it returns NULL.
*/
t_stack	*list_copy(t_stack **stack_a)
{
	t_stack	*new_list;  // Pointer to the new list.
	t_stack	*current;   // Pointer to traverse 'stack_a'.
	t_stack	*new_node;  // Pointer to a new node for 'new_list'.
	t_stack	*temp;      // Temporary pointer for memory deallocation.

	new_list = NULL;
	current = *stack_a;

	// Loop through 'stack_a' and copy each element to 'new_list'.
	while (current != NULL)
	{
		new_node = add_new_nody(current->nbr, current->index); // Create a new node with the same data as 'current'.
		if (new_node == NULL) // Check if memory allocation for the new node failed.
		{
			// If allocation fails, free the memory allocated for the copied list and return NULL.
			while (new_list != NULL)
			{
				temp = new_list;
				new_list = new_list->next;
				free(temp);
			}
			return (NULL);
		}

		add_node_to_stack(&new_list, new_node); // Add the new node to the 'new_list'.
		current = current->next; // Move to the next node in 'stack_a'.
	}

	return (new_list); // Return the pointer to the copied list 'new_list'.
}

/*
** Sorts the linked list 'head' using the selection sort algorithm.
** The selection sort algorithm repeatedly selects the smallest element
** and moves it to the beginning of the list (favorite position).
*/
void	sort_the_list(t_stack **head)
{
	int		swapped;   // Flag to indicate if elements were swapped during a pass.
	t_stack	*current;  // Pointer to traverse the list.
	t_stack	*tail;     // Pointer to the last sorted element (tail).

	// If the list is empty or has only one element, no need to sort.
	if (*head == NULL || (*head)->next == NULL)
		return;

	tail = NULL;
	swapped = 1;

	// Loop until no elements are swapped (list is sorted).
	while (swapped)
	{
		swapped = 0;
		current = *head;

		// Traverse the list and compare adjacent elements.
		while (current->next != tail)
		{
			if (current->nbr > current->next->nbr)
			{
				swap(current, current->next); // Swap the elements if they are not in order.
				swapped = 1;
			}
			current = current->next; // Move to the next node in the list.
		}

		tail = current; // Mark the last sorted element as 'tail'.
	}
}

/*
** Check and push elements from 'stack_a' to 'stack_b' based on the middle value.
** It pushes elements smaller than the 'middle' value to 'stack_b' from 'stack_a'.
** The number of elements pushed is based on the difference between the lengths of 'stack_a' and 'stack_b'.
*/
void	check_and_push(t_stack **stack_a, t_stack **stack_b, int middle)
{
	int	len_a;   // Length of 'stack_a'.
	int	len_b;   // Length of 'stack_b'.
	int	count;   // Counter variable.

	count = -1;
	len_a = get_list_length(*stack_a); // Get the length of 'stack_a'.
	len_b = 0;

	// Loop while there are more elements in 'stack_a' than in 'stack_b'.
	while ((len_a > len_b) && count < len_b)
	{
		// If the element at the beginning of 'stack_a' is smaller than 'middle', push it to 'stack_b'.
		if ((*stack_a)->index == 0 && (*stack_a)->nbr < middle)
			pb(stack_a, stack_b, 0);
		else
		{
			ra(stack_a, 0); // If not smaller, rotate 'stack_a'.
			count++;       // Increment the counter to keep track of rotations.
		}

		update_indexes(*stack_b); // Update the indexes of 'stack_b'.
		len_b = get_list_length(*stack_b); // Get the updated length of 'stack_b'.
		update_indexes(*stack_a); // Update the indexes of 'stack_a'.
		len_a = get_list_length(*stack_a); // Get the updated length of 'stack_a'.
	}

	return;
}

/*
** Sorts the stack using the quick sort algorithm.
** It creates a copy of 'stack_a', sorts the copy, and uses the sorted copy to find the middle value (middle or median).
** Elements smaller than the middle value are pushed to 'stack_b' using 'check_and_push' function.
** The process is repeated recursively until the stack is fully sorted.
** The 'stack_b' is then sorted using the selection sort algorithm (selection_sort_stack_b).
*/
void	quick_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		middle;    // Middle value of the stack (median or middle element).
	int		len_a;     // Length of 'stack_a'.
	t_stack	*copy;     // Copy of 'stack_a'.

	len_a = get_list_length(*stack_a); // Get the length of 'stack_a'.
	copy = list_copy(stack_a); // Create a copy of 'stack_a'.
	sort_the_list(&copy); // Sort the copied list.

	// Decide whether to use median or middle element as the 'middle' value based on the length of 'stack_a'.
	if (len_a > 25)
		middle = get_medd_value(copy); // Use median value for larger lists.
	else
		middle = get_mid_value(copy); // Use middle element for smaller lists.

	// Check and push elements from 'stack_a' to 'stack_b' based on the 'middle' value.
	check_and_push(stack_a, stack_b, middle);

	// If the length of 'stack_a' is 2, directly sort it using 'sort_due' and then 'selection_sort_stack_b' for 'stack_b'.
	if (len_a == 2)
	{
		sort_due(stack_a);
		selection_sort_stack_b(stack_a, stack_b);
	}
	else
		quick_sort(stack_a, stack_b); // Continue the quick sort recursively.

	free_lists(copy, *stack_b); // Free the memory used by the copied list and 'stack_b'.

	return;
}

/*
** Sorts 'stack_b' using the selection sort algorithm.
** It repeatedly selects the largest element and moves it to the top (top of the stack).
** The sorting is done in 'stack_b', while the sorted elements are moved back to 'a' using 'pa' operation.
*/
void	selection_sort_stack_b(t_stack **a, t_stack **stack_b)
{
	int	pos;         // Position of the largest element to be moved.
	int	count;       // Counter variable.
	int	biggest_pos; // Position of the largest element in 'stack_b'.
	int	moves;       // Number of rotations needed to bring the largest element to the top.

	while (*stack_b != NULL) // Loop until 'stack_b' is empty.
	{
		biggest_pos = find_big(stack_b, &pos); // Find the largest element in 'stack_b' and its position.
		moves = get_moves_to_top(*stack_b, pos); // Get the number of rotations needed to bring the largest element to the top.

		count = -1;
		while (++count < moves) // Rotate 'stack_b' the required number of times to bring the largest element to the top.
		{
			if (pos <= get_list_length(*stack_b) / 2)
				rb(stack_b, 0); // Rotate 'stack_b' clockwise if the largest element is closer to the bottom.
			else
				rrb(stack_b, 0); // Rotate 'stack_b' counter-clockwise if the largest element is closer to the top.

			update_indexes(*stack_b); // Update the indexes of 'stack_b'.
		}

		pa(a, stack_b, 0); // Move the largest element from 'stack_b' back to 'a'.

		update_indexes(*a); // Update the indexes of 'a'.
		update_indexes(*stack_b); // Update the indexes of 'stack_b'.

		// If the first two elements of 'a' are not in ascending order, swap them to maintain sorted order.
		if (*a && (*a)->next && (*a)->nbr > (*a)->next->nbr)
			sa(a, 0);
	}

	return;
}

