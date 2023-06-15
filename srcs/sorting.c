/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:18:35 by atucci            #+#    #+#             */
/*   Updated: 2023/06/15 14:55:37 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/push_swap.h"

void	sort_due(t_stack **stack_a)
{
	// swap the first two elements if they are not sorted
	ft_printf("I am sorting 2\n");
	if (is_sorted(*stack_a) == 0)
		sa(stack_a, 0);
 	update_indexes(*stack_a);
	return ;
}

void sort_tre(t_stack **stack_a)
{
		ft_printf("\033[1;32;41mI am sorting 3!\033[0m\n");
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
	int conto;//mallocing for stack B (?)
	t_stack **stack_b = (t_stack **)malloc(sizeof(t_stack *));
	*stack_b = NULL;
	//count = 0;
	ft_printf("\033[33mI am sorting the stack...\033[0m\n");

	//while  the stack is  not sorted
	while (is_sorted(*stack_a) == 0)
	{
		conto = get_list_length(*stack_a);// start with the while cicle
		while (conto > 3)
		{
			nb = find_big(stack_a, &pos); // looking for the smallest number
			moves = get_moves_to_top(*stack_a, pos);
			count = 0;
			while (count < moves)
			{
				/*if (moves == 1)
				{
					sa(stack_a, 0);
					update_indexes(*stack_a);
					print_stack(stack_a);
					break ;
				}*/
				if (pos <= get_list_length(*stack_a) / 2)
				{
					ra(stack_a, 0);
					update_indexes(*stack_a);
					print_stack(stack_a);
				}
				else
				{
					rra(stack_a, 0);
					update_indexes(*stack_a);
					print_stack(stack_a);
				}
				count++;
			}
		//while (get_list_legth(stack_a) > get_list)
		pb(stack_a, stack_b, 0); // pushing the smallest number to stack B
		update_indexes(*stack_a);
		//printf("\033[1;34mJust pushed to the stack b\nstack A size should descrease\033[0m\n");
		conto = get_list_length(*stack_a);
		}
	//
	//
	printf("``````````````````\n[this is the stack b]\n");
 	update_indexes(*stack_b);
	print_stack(stack_b);
	printf("``````````````````\n[this is the stack a]\n");
	// update_indexes(*stack_a);
		print_stack(stack_a);
	//
	update_indexes(*stack_a);
	if (get_list_length(*stack_a) == 2)
		sort_due(stack_a);
	else if (get_list_length(*stack_a) == 3) //&& is_sorted(*stack_a) == 0)
		sort_tre(stack_a);
	//ft_printf("\033[33m INfinite LOOPs fuck\033[0m\n");
	//exit(0);
	while(is_empty(stack_b) != 0 )
		{
			ft_printf("\033[1;36;43mtHiS  iS tHe lEnGht of staCk B {%d}!\033[0m\n", get_list_length(*stack_b));
			pa(stack_a, stack_b, 0);
		//	ft_printf("\033[1;36;43mtHiS  iS tHe lEnGht of staCk B {%d}!\033[0m\n", get_list_length(*stack_b));
			//
			//printf("fuck Im out\n");
			if (get_list_length(*stack_b) == 0)
			break ;
		}

	}
	// at this point, stack A is sorted, stack B is sorted

	//printf("THIS IS THE STACK b finally empty\n");
	//testa_toro(&stack_b);
	//update_indexes(stack_b);
	//print_stack(&stack_b);
		update_indexes(*stack_a);
		ft_printf("\033[32m%s\033[0m\n", "SORTING COMPLETED :)\n");
}

int is_sorted(t_stack *stack_a)
{
	t_stack *current = stack_a;
	int increasing = 1;
	int decreasing = 1;

	while (current != NULL && current->next != NULL)
	{
		if (current->nbr > current->next->nbr)
			increasing = 0;
		if (current->nbr < current->next->nbr)
			decreasing = 0;
		current = current->next;
	}

	if (increasing)
		return 1; // Sorted in increasing order
	else if (decreasing)
		return 2; // Sorted in decreasing order
	else
		return 0; // Not sorted
}


int	find_big(t_stack **stack_b, int *pos)
{
    int big;
	t_stack *current_node;

    *pos = 0;
    big = (*stack_b)->nbr; // Set big to the first element in stack_b
    current_node = *stack_b;
    while (current_node != NULL)
    {

		if (current_node->nbr > big) // if it's bigger than the one I already have...
        {
            big = current_node->nbr; // we update the big variable
            *pos = current_node->index;
        }
        current_node = current_node->next;
    }
	ft_printf("\033[1;36;45mBIGGEST number (%d) found at index [%d]!\033[0m\n", big, *pos);
    update_indexes(*stack_b);
	return (big);
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
	// try to  see where the issue is
	if ((*stack) == NULL)
		return (0);
	else
		return (1);
}
