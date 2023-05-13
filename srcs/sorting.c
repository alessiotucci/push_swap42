/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:18:35 by atucci            #+#    #+#             */
/*   Updated: 2023/05/13 14:36:56 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/push_swap.h"

void	sort_due(t_stack **stk)
{
	// If the first element in stack_a is greater than or equal to the second element,
	// swap the first two elements and increment the count
	//if (!(stk->stack_a[0] < stk->stack_a[1]))
	if (is_sorted(*stk) == 0)
		sa(stk, 0);
 	update_indexes(*stk);
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
    	update_indexes(*stk);
	}
}

void	sort_stack(t_stack **stk)
{
	int	pos;
	int nb;
	//mallocing for stack B (?)
	t_stack *stack_b = malloc(sizeof(t_stack));

	ft_printf("\033[33mI am sorting the stack...\033[0m\n");

	//while  the stack is  not sorted
	while (is_sorted(*stk) == 0) //&& (get_list_length(*stk) > get_list_length(stack_b)))
	{
		update_indexes(*stk);
		nb = find_small(*stk, &pos);
	// if the smallest number is already at the top
	// check the if statement here
		if (nb == (*stk)->nbr && pos == 1)
			sa(stk, 0);
		else if (nb == (*stk)->nbr && pos == 0)
			pb(stk, &stack_b, 0);
		else
		{
			//determine whether to rotate or reverse rotate
			if (pos <= (get_list_length(*stk) / 2))
				ra(stk, 0);
			else
				rra(stk, 0);
		}

	}
	// at this point, stack A is sorted, stack B is sorted

	printf("THIS IS THE STACK B\n");
	//testa_toro(&stack_b);
	update_indexes(stack_b);
	print_stack(&stack_b);
	//
	//while (stack_b)
	//	pa(&stack_b, stk, 0);
	if (stk)
		ft_printf("\033[32m%s\033[0m\n", "sorting completed\n");
		update_indexes(*stk);
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
	t_stack *current_node;

    *pos = 0;
    small = stk->nbr; // Set small to the first element in the list
    current_node = stk;
    while (current_node != NULL)
    {

		if (current_node->nbr < small) // if it's smaller than the one I already have...
        {
            small = current_node->nbr; // we update the small variable
            *pos = current_node->index;
        }
        current_node = current_node->next;
    }
	printf("smallest number\tfound at [%d]\tnumber:%d\t\n", *pos, small);
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

