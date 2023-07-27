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

/*
** Swaps the values of two stack nodes 'a' and 'b'.
** The 'nbr' field of the two nodes is swapped.
*/
void	swap(t_stack *a, t_stack *b)
{
	int	temp;

	temp = a->nbr;
	a->nbr = b->nbr;
	b->nbr = temp;
}

/*
** Finds the smallest element in the stack_a and its position.
** It traverses the stack_a to find the smallest element and its position (index).
** Returns the value of the smallest element.
*/
int	find_small(t_stack **stack_a, int *pos)
{
	int		small;          // Value of the smallest element in stack_a.
	t_stack	*current_node; // Pointer to traverse the stack_a.

	*pos = 0;
	small = (*stack_a)->nbr; // Initialize 'small' with the value of the first element in stack_a.
	current_node = *stack_a;

	// Loop through stack_a to find the smallest element and its position.
	while (current_node != NULL)
	{
		if (current_node->nbr < small)
		{
			small = current_node->nbr; // Update 'small' with the value of the current element if it is smaller.
			*pos = current_node->index; // Update 'pos' with the position of the smallest element.
		}
		current_node = current_node->next; // Move to the next node in stack_a.
	}
	return (small); // Return the value of the smallest element in stack_a.
}

/*
** Frees the memory allocated for a string array 'tab'.
** It also frees the individual strings in the array.
** Returns 0 after freeing the memory.
*/
int	free_split(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
	{
		free(tab[count++]); // Free each individual string in the array.
	}
	free(tab); // Free the array itself.
	return (0);
}

/*
** Updates the indexes of the stack nodes and returns the length of the stack.
** It updates the 'index' field of each node in the stack.
** Returns the length of the stack.
*/
int	update_indexes_and_get_length(t_stack *head)
{
	int		count; // Counter variable.
	t_stack	*node;  // Pointer to traverse the stack.

	count = 0;
	node = head;
	while (node != NULL)
	{
		node->index = count; // Update the 'index' of the current node with the counter value.
		node = node->next; // Move to the next node in the stack.
		count++; // Increment the counter.
	}
	return (count); // Return the length of the stack.
}

/*
** Custom version of atoi that handles the minimum and maximum integer values.
** Converts the initial portion of a string 's' to a long integer representation.
** Handles leading whitespaces, signs, and overflows (INT_MAX and INT_MIN).
** Returns the converted long integer value on success, or calls 'print_exit' function on overflow.
*/
long	ft_atoi_plus(const char *s)
{
	long	num;    // The resulting long integer.
	long	sign;   // Sign of the number (1 for positive, -1 for negative).
	int		i;      // Index to traverse the string 's'.

	num = 0;
	sign = 1;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++; // Skip leading whitespaces.

	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1; // Handle negative sign.

		i++; // Move past the sign character.
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		num = (num * 10) + (s[i] - '0'); // Calculate the number using digits from the string.
		i++; // Move to the next digit.
	}

	if ((sign * num) > INT_MAX || (sign * num) < INT_MIN)
		return (print_exit()); // Check for overflow and call 'print_exit' function if overflow occurs.

	return (sign * num); // Return the converted long integer value.
}
