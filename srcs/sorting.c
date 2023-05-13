/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:18:35 by atucci            #+#    #+#             */
/*   Updated: 2023/05/13 17:46:36 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/push_swap.h"

void	sort_due(t_stack **stack_a)
{
	// If the first element in stack_a is greater than or equal to the second element,
	// swap the first two elements and increment the count
	//if (!(stack_a->stack_a[0] < stack_a->stack_a[1]))
	ft_printf("I am sorting 2\n");
	if (is_sorted(*stack_a) == 0)
		sa(stack_a, 0);
 	update_indexes(*stack_a);
	return ;
}

void sort_tre(t_stack **stack_a)
{
		ft_printf("I am sorting 3\n");
    // If the stack has less than three nodes, return without doing anything
    if (!*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
        return;

    int a = (*stack_a)->nbr;
    int b = (*stack_a)->next->nbr;
    int c = (*stack_a)->next->next->nbr;

    // Continue until the first three elements of the stack are in ascending order
    while (!(a < b && b < c))
    {
        // If the second element is less than the first and less than the third,
        // swap the first two elements
        if (b < a && a < c)
            sa(stack_a, 0);
        // If the third element is less than the second and less than the first,
        // swap the first two elements
        else if (c < b && b < a)
            sa(stack_a, 0);
        // If the first element is less than the third and the third is less than the second,
        // swap the first and the third elements
        else if (a < c && c < b)
            rra(stack_a, 0);
        // If the second element is less than the third and the third is less than the first,
        // rotate the stack so that the second element becomes the first
        else if (b < c && c < a)
            ra(stack_a, 0);
        // If the third element is less than the first and the first is less than the second,
        // rotate the stack so that the last element becomes the first
        else if (c < a && a < b)
            rra(stack_a, 0);

        // Update the values of a, b, and c
        a = (*stack_a)->nbr;
        b = (*stack_a)->next->nbr;
        c = (*stack_a)->next->next->nbr;
    	update_indexes(*stack_a);
	}
}

void	sort_stack(t_stack **stack_a)
{
	int	pos;
	int nb;
	int moves;
	int count;
	//mallocing for stack B (?)
	t_stack *stack_b = NULL;
	count = 0;
	ft_printf("\033[33mI am sorting the stack...\033[0m\n");

	//while  the stack is  not sorted
	while (is_sorted(*stack_a) == 0)
	{
		nb = find_small(*stack_a, &pos); // looking for the smallest number
		moves = get_moves_to_top(*stack_a, pos);
		while (count < moves)
		{
			if (pos < get_list_length(*stack_a) / 2)
				ra(stack_a, 0);
			else
				rra(stack_a, 0);
			count++;
		}
	pb(stack_a, &stack_b, 0); // pushing the smallest number to stack B
	//
	//
	printf("``````````````````\nthis is the stack b\n");
	print_stack(&stack_b);
	printf("``````````````````\nthis is the stack a\n");
		update_indexes(*stack_a);
		print_stack(stack_a);
	//
	update_indexes(*stack_a);
	if (get_list_length(*stack_a) == 2)
		sort_due(stack_a);
	else if (get_list_length(*stack_a) == 3)
		sort_tre(stack_a);
	ft_printf("\033[33m INfinite LOOPs fuck issie with the stack b goddamet\033[0m\n");
	//ft_printf("the lenght of the stack b should  be %d\n", get_list_length(stack_b));
	while (is_empty(&stack_b) != 0)
		pa(&stack_b, stack_a, 0);


	}
	// at this point, stack A is sorted, stack B is sorted

	printf("THIS IS THE STACK b finally empty\n");
	//testa_toro(&stack_b);
	//update_indexes(stack_b);
	//print_stack(&stack_b);
		update_indexes(*stack_a);
		ft_printf("\033[32m%s\033[0m\n", "sorting completed\n");
}

int	is_sorted(t_stack *stack_a)
{
	t_stack *current = stack_a;

	while (current != NULL && current->next != NULL)
	{
		if (current->nbr > current->next->nbr)
			return (0); // Not sorted
	current = current->next;
	}
return (1); // sorted :)
}

int	find_small(t_stack *stack_a, int *pos)
{
    int small;
	t_stack *current_node;

    *pos = 0;
    small = stack_a->nbr; // Set small to the first element in the list
    current_node = stack_a;
    while (current_node != NULL)
    {

		if (current_node->nbr < small) // if it's smaller than the one I already have...
        {
            small = current_node->nbr; // we update the small variable
            *pos = current_node->index;
        }
        current_node = current_node->next;
    }
	printf("smallest number\tfound\n");
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

int get_moves_to_top(t_stack *stack, int index)
{
    int size = get_list_length(stack);
    int moves = 0;

    if (index == 0) // element is already at the top
	return 0;
// calculate the number of moves needed to bring the element to the top
    if (index <= size / 2)
	// element is in the first half of the stack
		moves = index;
	else
	// element is in the second half of the stack
        moves = size - index;
	return moves;
}
int is_empty(t_stack **stack)
{
	if ((*stack) == NULL)
		return (0);
	else
		return (1);
}
