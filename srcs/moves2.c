/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:37:30 by atucci            #+#    #+#             */
/*   Updated: 2023/06/14 11:45:48 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/push_swap.h"

// ra (rotate a) : shift up all elements of stack a by 1.
// The first element becomes the last one.
void ra(t_stack **a, int j)
{
    t_stack *tmp;
    t_stack *first;

    if (!*a || !(*a)->next)
        return;
    tmp = *a;
    first = tmp;
    *a = (*a)->next;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = first;
    first->next = NULL;
    if (j == 0)
        write(1, "ra\n", 3);
}




// Function to rotate stack B
void rb(t_stack **b, int j)
{
    t_stack *tmp;
    t_stack *first;

    if (!*b || !(*b)->next)
        return;
    tmp = *b;
    first = tmp;
    *b = (*b)->next;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = first;
    first->next = NULL;
    if (j == 0)
        write(1, "rb\n", 3);
}


// Function to rotate both stack A and stack B
void rr(t_stack *stk)
{
/*	int tmp_a;
	int tmp_b;
	int i;

	if (stk->la < 2 || stk->lb < 2) // if there's only one element or less in either stack, return
		return ;
	tmp_a = stk->stack_a[0]; // save the first element of stack A
	tmp_b = stk->stack_b[0]; // save the first element of stack B
	i = 0;
	while (i < stk->la - 1) // shift every element in stack A one position to the left
	{
		stk->stack_a[i] = stk->stack_a[i + 1];
		i++;
	}
	stk->stack_a[i] = tmp_a; // place the saved element at the end of stack A
	i = 0;
	while (i < stk->lb - 1) // shift every element in stack B one position to the left
	{
		stk->stack_b[i] = stk->stack_b[i + 1];
		i++;
	}
	stk->stack_b[i] = tmp_b; // place the saved element at the end of stack B
*/if (stk)
	write(1, "rr\n", 3); // print "rr" to standard output
}

// Function to reverse rotate stack A
// rra (reverse rotate a) : shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_stack **a, int j)
{
	t_stack	*tmp;
	int		i;

	if (!*a || !(*a)->next)
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		write(1, "rra\n", 4);
}



// This function rotates stack B downwards by one position
void rrb(t_stack **b, int j)
{
	t_stack *tmp;
	int i;

	if (!*b || !(*b)->next)
		return;
	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		*b = (*b)->next;
		i++;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		write(1, "rrb\n", 4);
}


t_stack	*ft_lstlasty(t_stack *lst)
{
	// check the list first
	if (lst == NULL)
		return (NULL);

	// traverse the list backwards until we reach the last element
	while (lst->prev != NULL)
		lst = lst->prev;

	return (lst);
}

