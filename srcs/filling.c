/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:37:11 by atucci            #+#    #+#             */
/*   Updated: 2023/04/28 11:43:09 by atucci           ###   ########.fr       */
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

	count = 0;
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
		ft_printf("yy%d\n", stack->stack_a[count - 1]);
		count++;
	}
}

