/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:37:30 by atucci            #+#    #+#             */
/*   Updated: 2023/04/28 11:54:08 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/push_swap.h"

// Function to rotate stack A
void ra(t_stack *stk)
{
	int tmp;
	int i;

	i = 0;
	if (stk->la < 2) // if there's only one element or less in stack A, return
		return ;
	tmp = stk->stack_a[0]; // save the first element of stack A
	while (i < stk->la - 1) // shift every element one position to the left
	{
		stk->stack_a[i] = stk->stack_a[i + 1];
		i++;
	}
	stk->stack_a[i] = tmp; // place the saved element at the end of the stack
	write(1, "ra\n", 3); // print "ra" to standard output
}

// Function to rotate stack B
void rb(t_stack *stk)
{
	int tmp;
	int i;

	i = 0;
	if (stk->lb < 2) // if there's only one element or less in stack B, return
		return ;
	tmp = stk->stack_b[0]; // save the first element of stack B
	while (i < stk->lb - 1) // shift every element one position to the left
	{
		stk->stack_b[i] = stk->stack_b[i + 1];
		i++;
	}
	stk->stack_b[i] = tmp; // place the saved element at the end of the stack
	write(1, "rb\n", 3); // print "rb" to standard output
}

// Function to rotate both stack A and stack B
void rr(t_stack *stk)
{
	int tmp_a;
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
	write(1, "rr\n", 3); // print "rr" to standard output
}

// Function to reverse rotate stack A
void rra(t_stack *stk)
{
	int tmp;
	int i;

	i = stk->la - 1;
	tmp = stk->stack_a[i]; // save the last element of stack A
	while (i > 0) // shift every element one position to the right
	{
		stk->stack_a[i] = stk->stack_a[i - 1];
		i--;
	}
	stk->stack_a[0] = tmp; // place the saved element at the beginning of stack A
	write(1, "rra\n", 4); // print "rra" to standard output
}

/
// This function rotates stack B downwards by one position
void rrb(t_stack *stk)
{
	int tmp; // variable to store the top element of stack B
	int i; // loop counter
	i = stk->lb - 1;
	tmp = stk->stack_b[i];
	while (i > 0) // shift elements of stack B downwards
	{
		stk->stack_b[i] = stk->stack_b[i - 1];
		i--;
	}
	stk->stack_b[0] = tmp; // place the top element at the bottom of stack B
	write(1, "rrb\n", 4); // print the name of the operation to stdout
}
