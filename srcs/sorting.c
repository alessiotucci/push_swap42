/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:18:35 by atucci            #+#    #+#             */
/*   Updated: 2023/05/09 16:25:29 by atucci           ###   ########.fr       */
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
		sa(&stk, 0);
		count++;
	}
	// Print the number of moves made
	ft_printf("I did it in %d moves\n", count);
	return ;
}

void	sort_tre(t_stack *stk)
{
/*	// Continue until the first three elements of stack_a are in ascending order
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
 */   if (stk)
	ft_printf("i have no time");
	return ;
}

void	sort_stack(t_stack *stk)
{
/*	int pos;
	int nb;

	if (stk)
	ft_printf("I am working on it\n");
	// while the stack  is not sorted
	if (is_sorted(stk) == 1)
	{
		ft_printf("already sorted\n");
		return ;
	}
	while (is_sorted(stk) == 0)
	{
	nb = find_small(stk, &pos);
	//ft_printf("the smallest int is: %d\n", nb);
	if (stk->stack_a[0] == nb)
	{
		pb(stk);
		//stack->lb++;
	}
	else 
		rra(stk);
	// there is room for improvement;
	}
// at this point i need to empty the stack b if the stack a is sorted.
// I need to check if the stack b is sorted in decresing order
	if (stk->lb <= 2 && is_B_sorted(stk) == 1)
		pa(stk);
*/
	if (stk)
	ft_printf("algoritmo generale di sorting:");
	return ;
}

int	is_sorted(t_stack *stk)
{
	t_stack *current = stk;

	while (current != NULL && current->next != NULL)
	{
		if (current->nbr > current->next->nbr)
			return (0); // Not sorted
	current = current->next;
	}
return (1); // sorted :)
}

int	find_small(t_stack *stk, int *pos)
{
    int small;
    int count;

    count = 0;
    *pos = 0;
    small = stk->next->nbr; // Set small to the first element in the list
    t_stack *current_node = stk->next;
    while (current_node != NULL)
    {
        if (current_node->nbr < small) // if it's smaller than the one I already have...
        {
            small = current_node->nbr; // we update the small variable
            *pos = count;
        }
        current_node = current_node->next;
        count++;
    }

    return (small);
}

void testa_toro(t_stack **stack)
{
	if (*stack == NULL)
		return;
	t_stack *temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
		free(temp);
}

