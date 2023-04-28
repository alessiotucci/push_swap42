/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:18:35 by atucci            #+#    #+#             */
/*   Updated: 2023/04/28 16:44:57 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/push_swap.h"

void	sort_due(t_stack *stk)
{
	int	count;

	count = 0;
	// If the first element in stack_a is greater than or equal to the second element,
	// swap the first two elements and increment the count
	//if (!(stk->stack_a[0] < stk->stack_a[1]))
	if (is_sorted(stk) == 0)
	{
		sa(stk);
		count++;
	}
	// Print the number of moves made
	ft_printf("I did it in %d moves\n", count);
	return ;
}

void	sort_tre(t_stack *stk)
{
	// Continue until the first three elements of stack_a are in ascending order
	while (!(stk->stack_a[0] < stk->stack_a[1]
			&& stk->stack_a[1] < stk->stack_a[2]))
	{
		// If the second element is less than the first and less than the third,
		// swap the first two elements
		if (stk->stack_a[1] < stk->stack_a[0]
			&& stk->stack_a[0] < stk->stack_a[2])
			sa(stk);
		// If the third element is less than the second and less than the first,
		// swap the first two elements
		if (stk->stack_a[2] < stk->stack_a[1]
			&& stk->stack_a[1] < stk->stack_a[0])
			sa(stk);
		// If the first element is less than the third and the third is less than the second,
		// swap the first two elements
		if (stk->stack_a[0] < stk->stack_a[2]
			&& stk->stack_a[2] < stk->stack_a[1])
			sa(stk);
		// If the second element is less than the third and the third is less than the first,
		// rotate the stack_a so that the second element becomes the first
		if (stk->stack_a[1] < stk->stack_a[2]
			&& stk->stack_a[2] < stk->stack_a[0])
			ra(stk);
		// If the third element is less than the first and the first is less than the second,
		// rotate the stack_a so that the last element becomes the first
		if (stk->stack_a[0] < stk->stack_a[1]
			&& stk->stack_a[2] < stk->stack_a[0])
			rra(stk);
	}
	// Print the number of moves made
	ft_printf("I did it at least 2  moves\n");
	return ;
}

void	sort_stack(t_stack *stk)
{
	if (stk)
	ft_printf("I am working on it");

}

int	is_sorted(t_stack *stk)
{
	int	i;

	i = 0;
	while (i < stk->la - 1)
	{
		if (stk->stack_a[i] > stk->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

