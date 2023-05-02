/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:37:11 by atucci            #+#    #+#             */
/*   Updated: 2023/05/02 11:43:39 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/push_swap.h"

//This function takes a string of numbers as input and splits them into separate integers to store in stack_a
void	split_num_in_stack(char *number, t_stack *stack)
{
	int	count;
	char	**input_number;

	count = 0;
	//allocate memory for stack_a
	stack->stack_a = malloc(stack->la * sizeof(int));
	if (stack->stack_a == NULL)
		return ;
	//split the string into individual numbers and store them in input_number array
	input_number = ft_split(number, ' ');
	//loop through the array of input numbers, converting each string to integer and storing them in stack_a array
	while (number[count])
	{
		//convert the input string to integer and store it in stack_a array
		stack->stack_a[count] = ft_atoi(input_number[count]);
		//print the current integer value and its index
		ft_printf("Stack A [%d]: %d\n", count, stack->stack_a[count]);
		//free the memory allocated for the current input number
		free (input_number[count]);
		count++;
	}
	//free the memory allocated for the input_number array
	free(input_number);
}

//This function fills the stack_a array with integers given as arguments to the program
void	fill_stack(int ac, char *av[], t_stack *stack)
{
	int count;

	count = 1;
	//set the size of the stack to the number of input arguments minus one
	stack->la = ac - 1;
	//allocate memory for stack_a
	stack->stack_a = malloc(stack->la * sizeof(int));
	if (stack->stack_a == NULL)
		return ;
	//loop through the input arguments, converting each string to integer and storing them in stack_a array
	while (count < ac)
	{
		//convert the input string to integer and store it in stack_a array
		stack->stack_a[count - 1] = ft_atoi(av[count]);
		//print the current integer value
		ft_printf("stack_a: [%d] %d\n", count,  stack->stack_a[count - 1]);
		count++;
	}
// 	CHATGPT SUGGERISCE
		stack->stack_b = (int *)malloc(sizeof(int) * stack->la);
		if (stack->stack_b == NULL)
			return ;
		stack->lb = 0;
}

/*
** This function counts the number of integers in a string, delimited by spaces.
** It takes a string as input and returns an integer count.
*/
int	count_elements(char *str)
{
	int	count;
	int	numbers;

	numbers = 0;
	count = 0;
	while (str[count])
	{
		if (str[count] == ' ')
			numbers++; // Increment the count of numbers for each space found
		count++;
	}
	return (numbers + 1); // Add 1 to account for the last number (no space after it)
}

/*
** This function checks if the characters in a string are valid integers or '-'.
** It takes a string as input and returns 1 if the string is valid, 0 if not.
*/
int	correct_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] != '-' && str[i] != ' ') // Check if character is not '-' or space
			&& (!(str[i] >= '0' && str[i] <= '9'))) // Check if character is not a digit
		{
			ft_printf("ERRORE: sei un cojone\n"); // Print error message if character is invalid
			return (0);
		}
		i++;
	}
	return (1); // Return 1 if all characters are valid integers or '-'.
}


void	print_stack(t_stack *stk)
{
	// Print the contents of stack_a
	printf("stack_a: ");
	int i = 0;
	while (i < stk->la) // Loop through the stack_a array
	{
		printf("%d ", stk->stack_a[i]); // Print each value of stack_a
		i++;
	}
}
