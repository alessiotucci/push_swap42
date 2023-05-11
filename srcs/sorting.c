/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:18:35 by atucci            #+#    #+#             */
/*   Updated: 2023/05/11 12:40:28 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/push_swap.h"

void	sort_due(t_stack *stk)
{
	// If the first element in stack_a is greater than or equal to the second element,
	// swap the first two elements and increment the count
	//if (!(stk->stack_a[0] < stk->stack_a[1]))
	if (is_sorted(stk) == 0)
		sa(&stk, 0);
	return ;
}

void sort_tre(t_stack **stk)
{
    // If the stack has less than three nodes, return without doing anything
    if (!*stk || !(*stk)->next || !(*stk)->next->next)
        return;

    int a = (*stk)->nbr;
    int b = (*stk)->next->nbr;
    int c = (*stk)->next->next->nbr;

    // Continue until the first three elements of the stack are in ascending order
    while (!(a < b && b < c))
    {
        // If the second element is less than the first and less than the third,
        // swap the first two elements
        if (b < a && a < c)
            sa(stk, 0);
        // If the third element is less than the second and less than the first,
        // swap the first two elements
        else if (c < b && b < a)
            sa(stk, 0);
        // If the first element is less than the third and the third is less than the second,
        // swap the first and the third elements
        else if (a < c && c < b)
            rra(stk, 0);
        // If the second element is less than the third and the third is less than the first,
        // rotate the stack so that the second element becomes the first
        else if (b < c && c < a)
            ra(stk, 0);
        // If the third element is less than the first and the first is less than the second,
        // rotate the stack so that the last element becomes the first
        else if (c < a && a < b)
            rra(stk, 0);

        // Update the values of a, b, and c
        a = (*stk)->nbr;
        b = (*stk)->next->nbr;
        c = (*stk)->next->next->nbr;
    }
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

