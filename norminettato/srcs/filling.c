/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:37:11 by atucci            #+#    #+#             */
/*   Updated: 2023/06/26 18:41:14 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus/libft.h"
#include "../incl/push_swap.h"

t_stack	*split_num_in_stack(char *number)
{
	int		count;
	char	**input_number;
	t_stack	*stack;
	t_stack	*new_node;

	count = 0;
	input_number = ft_split(number, ' ');
	if (correct_char(number) == 0)
	{
		free_split(input_number);
		return (NULL);
	}
	stack = NULL;
	while (input_number[count])
	{
		new_node = create_new_node(input_number[count], count);
		if (!new_node)
			return (NULL);
		add_node_to_stack(&stack, new_node);
		count++;
	}
	free_split(input_number);
	return (stack);
}
/*
t_stack	*fill_stack(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*new_node;
	int		arg_index;
	int		num_index;
	char	**input_numbers;

	stack = NULL;
	arg_index = 1;
	while (arg_index < ac)
	{
		if (correct_char(av[arg_index]) == 0)
			return (NULL);
		input_numbers = ft_split(av[arg_index], ' ');
		num_index = 0;
		while (input_numbers[num_index])
		{
			new_node = create_new_node(input_numbers[num_index], num_index);
			if (!new_node)
				exit(1);
			new_node->nbr = ft_atoi(input_numbers[num_index]);
			if (stack != NULL)
			new_node->index = stack->index++;
			else
				new_node->index = 0;
			add_node_to_stack(&stack, new_node);
			num_index++;
		}
		free(input_numbers);
		arg_index++;
	}
	return (stack);
}*/

t_stack	*fill_stack(int ac, char **av)
{
	t_stack	*stck;
	int		i;

	stck = NULL;
	i = 1;
	while (i < ac)
	{
		if (correct_char(av[i]) == 0)
			exit(1);
		if (!process_arguments(av[i], &stck))
			exit(1);
		i++;
	}
	return (stck);
}

int	process_arguments(char *arg, t_stack **stack)
{
	char	**input_numbers;
	int		num_index;
	t_stack	*new_node;

	input_numbers = ft_split(arg, ' ');
	if (!input_numbers)
		return (0);
	num_index = 0;
	while (input_numbers[num_index])
	{
		new_node = create_new_node(input_numbers[num_index], num_index);
		if (!new_node)
			return (free_split(input_numbers));
		new_node->nbr = ft_atoi_plus(input_numbers[num_index]);
		if (*stack)
			new_node->index = (*stack)->index++;
		else
			new_node->index = 0;
		add_node_to_stack(stack, new_node);
		num_index++;
	}
	free_split(input_numbers);
	return (1);
}

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
			ft_printf("Error\n");
			return (0);
		}
		if ((str[i] != '-' && str[i] != ' ')
			&& (!(str[i] >= '0' && str[i] <= '9')))
		{
			ft_printf("Error\n");
			return (0);
		}
	i++;
	}
	return (1);
}

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
