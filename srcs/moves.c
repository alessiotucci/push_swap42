/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:37:20 by atucci            #+#    #+#             */
/*   Updated: 2023/04/28 11:48:03 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Including necessary header files
#include "../libft/libft.h"
#include "../incl/push_swap.h"

// Function to push the top element from Stack B to Stack A
void pa(t_stack *stk)
{
// If Stack B is empty, return without any action
if (!stk->stack_b)
return ;
// Increment the pointer to the top element in Stack A
stk->stack_a++;
// Shifting elements in Stack A to create space for the new element
int i = stk->la - 1;
while (i > 0)
{
stk->stack_a[i] = stk->stack_a[i - 1];
i--;
}
// Moving the top element from Stack B to the bottom of Stack A
stk->stack_a[0] = stk->stack_b[0];
// Shifting remaining elements in Stack B to fill the void left by the removed element
i = 0;
while (i < stk->lb - 1)
{
stk->stack_b[i] = stk->stack_b[i + 1];
i++;
}
// Decrement the size of Stack B
stk->lb--;
// Print the push operation
write(1, "pa\n", 3);
}

// Function to push the top element from Stack A to Stack B
void pb(t_stack *stk)
{
// If Stack A is empty, return without any action
if (!stk->stack_a)
return ;
// Increment the pointer to the top element in Stack B
stk->stack_b++;
// Shifting elements in Stack B to create space for the new element
int i = stk->lb - 1;
while (i > 0)
{
stk->stack_b[i] = stk->stack_b[i - 1];
i--;
}
// Moving the top element from Stack A to the bottom of Stack B
stk->stack_b[0] = stk->stack_a[0];
// Shifting remaining elements in Stack A to fill the void left by the removed element
i = 0;
while (i < stk->la - 1)
{
stk->stack_a[i] = stk->stack_a[i + 1];
i++;
}
// Decrement the size of Stack A
stk->la--;
// Print the push operation
write(1, "pb\n", 3);
}

// Function to swap the first two elements in Stack A
void sa(t_stack *stk)
{
// If Stack A has less than two elements, return without any action
if (!(stk->stack_a[0] || stk->stack_a[1]))
return ;
// Swap the first two elements of Stack A
int tmp = stk->stack_a[1];
stk->stack_a[1] = stk->stack_a[0];
stk->stack_a[0] = tmp;
// Print the swap operation
write(1, "sa\n", 3);
}

// Function to swap the first two elements in Stack B
void sb(t_stack *stk)
{
// If Stack B has less than two elements, return without any action
if (!(stk->stack_b[0] || stk->stack_b[1]))
return ;
// Swap the first two elements of Stack B
int tmp = stk->stack_b[1];
stk->stack_b[1] = stk->stack_b[0];
stk->stack_b[0] = tmp;
// Print the swap operation
write(1, "sb\n", 3);
}

//
