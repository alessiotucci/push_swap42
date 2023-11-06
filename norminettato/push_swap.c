/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:34:07 by atucci            #+#    #+#             */
/*   Updated: 2023/06/26 17:56:04 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_plus/libft.h"
#include "incl/push_swap.h"

int	has_repetitions(t_stack *stack)
{
	t_stack	*current;

	while (stack != NULL)
	{
		current = stack->next;
		while (current != NULL)
		{
			if (stack->nbr == current->nbr)
				return (ft_printf("Error\n"));
			current = current->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	get_list_length(t_stack *head)
{
	int	count;

	count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	update_indexes(head);
	return (count);
}

int	print_exit(void)
{
	ft_printf("Error\n");
	exit(0);
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2)
		stack_a = split_num_in_stack(av[1]);
	else if (ac > 2)
		stack_a = fill_stack(ac, av);
	if (has_repetitions(stack_a) != 0 || is_sorted(stack_a))
		return (free_lists(stack_a, stack_b));
	len = get_list_length(stack_a);
	if (len == 2)
		sort_due(&stack_a);
	else if (len == 3)
		sort_tre(&stack_a);
	else if (get_list_length(stack_a) < 10)
		sort_stack(&stack_a, &stack_b);
	else
		quick_sort(&stack_a, &stack_b);
	free_lists(stack_a, stack_b);
	return (0);
}
