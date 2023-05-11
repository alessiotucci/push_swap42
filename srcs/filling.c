/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:37:11 by atucci            #+#    #+#             */
/*   Updated: 2023/05/11 11:58:28 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/push_swap.h"

//This function takes a string of numbers as input and splits them into separate integers to store in stack_a
void	split_num_in_stack(char *number, t_stack *stack)
{
    int     count = 0;
    char    **input_number;

    // split the string into individual numbers and store them in input_number array
	input_number = ft_split(number, ' ');
	if (correct_char(number) == 0)
		return ;

    // loop through the array of input numbers, converting each string to integer and storing them in the linked list
    while (input_number[count])
    {
        // create a new node for the linked list
        t_stack *new_node = (t_stack*)malloc(sizeof(t_stack));
        if (!new_node)
            return ;

        // fill up the node with the integer value, index and pointers to next and previous nodes
        new_node->nbr = ft_atoi(input_number[count]);
        new_node->index = count;
        new_node->next = NULL;
        new_node->prev = NULL;

        // add the node to the end of the linked list
        if (!stack->next)
        {
            stack->next = new_node;
            stack->prev = new_node;
        }
        else
        {
            new_node->prev = stack->prev;
            stack->prev->next = new_node;
            stack->prev = new_node;
        }

        //print the current integer value and its index
        ft_printf("Stack A [%d]: %d\n", count, new_node->nbr);
        count++;
    }

    // free the memory allocated for the input_number array
    free(input_number);
	return ;
}

//This function fills the stack_a array with integers given as arguments to the program
void	fill_stack(int ac, char *av[], t_stack *stack)
{
	char **input_numbers;
	int arg_index;
	
	arg_index = 1;
    while (arg_index < ac)
    {
        if (correct_char(av[arg_index]) == 0)
			return ;
		input_numbers = ft_split(av[arg_index], ' ');
        int num_index = 0;
        while (input_numbers[num_index])
        {
            t_stack *new_node = (t_stack*)malloc(sizeof(t_stack));
            if (!new_node)
                exit(1);
            new_node->nbr = ft_atoi(input_numbers[num_index]);
            new_node->index = stack->index++;
            new_node->next = NULL;
            new_node->prev = NULL;
            if (!stack->next)
            {
                stack->next = new_node;
                new_node->prev = stack;
            }
            else
            {
                t_stack *last_node = stack->next;
                while (last_node->next)
                    last_node = last_node->next;
                last_node->next = new_node;
                new_node->prev = last_node;
            }
            num_index++;
        }
		free(input_numbers);
        arg_index++;
    }
	ft_printf("prima di tagliare la testa al toro\n");
	print_stack(&stack);
	return ;
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
			ft_printf("\t\t\tERRORE\n"); // Print error message if character is invalid
			return (0);
		}
		i++;
	}
	return (1); // Return 1 if all characters are valid integers or '-'.
}

void	print_stack(t_stack **stk)
{
	t_stack	*tmp;

	tmp = *stk;
	while (tmp != NULL) // Loop through the LIST
	{
		ft_printf(" [%d]  %d\n", tmp->index, tmp->nbr); // Print each value of stack_a
		tmp = tmp->next;
	}
}

