/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:37:11 by atucci            #+#    #+#             */
/*   Updated: 2023/07/27 18:44:41 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus/libft.h"
#include "../incl/push_swap.h"

/*
** Splits the input number string into a stack of t_stack nodes.
** Each node in the stack represents a number from the input string.
** The index of each node corresponds to its position in the input string.
** Returns a pointer to the created stack.
** If there's an error, it returns NULL.
*/
t_stack	*split_num_in_stack(char *number)
{
	int		count;
	char	**input_number;
	t_stack	*stack;
	t_stack	*new_node;

	count = 0;
	input_number = ft_split(number, ' '); // Split the input number string into an array of strings.
	if (correct_char(number) == 0) // Check if the characters in the input string are valid.
	{
		free_split(input_number); // Free the memory allocated for the split strings.
		return (NULL);
	}

	stack = NULL;
	while (input_number[count])
	{
		new_node = create_new_node(input_number[count], count); // Create a new node for each number in the input string.
		if (!new_node) // Check if memory allocation for the new node failed.
			return (NULL);

		add_node_to_stack(&stack, new_node); // Add the new node to the stack.
		count++;
	}

	free_split(input_number); // Free the memory allocated for the split strings.
	return (stack);
}

/*
** Fills the stack with numbers from the input arguments (ac and av).
** Each argument may contain multiple numbers separated by spaces.
** The index of each node corresponds to its position in the input arguments.
** Returns a pointer to the filled stack.
** If there's an error, it exits the program.
*/
t_stack	*fill_stack(int ac, char **av)
{
	t_stack	*stck;
	int		i;

	stck = NULL;
	i = 1;
	while (i < ac)
	{
		if (correct_char(av[i]) == 0) // Check if the characters in the input argument are valid.
			exit(1); // If not valid, exit the program with an error.

		if (!process_arguments(av[i], &stck)) // Process individual argument and add it to the stack.
			exit(1); // If there's an error in processing, exit the program with an error.

		i++;
	}
	return (stck);
}

/*
** Checks if the characters in the input string are valid.
** Returns 1 if all characters are valid, 0 otherwise.
** Prints an error message if there are invalid characters.
*/
int	correct_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+')
			i++;
		if (str[i] == '-' && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
		{
			ft_printf("Error\n"); // Print an error message if '-' is not followed by a digit.
			return (0);
		}
		if ((str[i] != '-' && str[i] != ' ') && (!(str[i] >= '0' && str[i] <= '9')))
		{
			ft_printf("Error\n"); // Print an error message if there's an invalid character.
			return (0);
		}
		i++;
	}
	return (1); // All characters are valid.
}

/*
** Prints the contents of the stack.
** Each node is printed with its index and value.
*/
void	print_stack(t_stack **stk)
{
	t_stack	*tmp;

	tmp = *stk;
	while (tmp != NULL)
	{
		ft_printf(" [%d]  %d\n", tmp->index, tmp->nbr);
		tmp = tmp->next;
	}
}
