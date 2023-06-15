/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:37:20 by atucci            #+#    #+#             */
/*   Updated: 2023/06/15 13:01:03 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Including necessary header files
#include "../libft/libft.h"
#include "../incl/push_swap.h"

// Function to push the top element from Stack B to Stack A
void pa(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (j == 0)
ft_printf("\033[0;37;46mpa\033[0m\n");

}

// Function to push the top element from Stack A to Stack B
void pb(t_stack **stack_a, t_stack **stack_b, int j)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	if (j == 0)
		ft_printf("\033[1;36;43mPB!\033[0m\n");
}

// Function to swap the first two elements in Stack A

void sa(t_stack **a, int j)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (j == 0)
		write(1, "sa\n", 3);
}

// Function to swap the first two elements in Stack B
void sb(t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (j == 0)
		write(1, "sb\n", 3);
}

void update_indexes(t_stack *stack)
{
    int i;
	i = 0;
    t_stack *node = stack;

    while (node != NULL)
    {
        node->index = i;
        node = node->next;
        i++;
    }
}

