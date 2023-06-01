/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:46:30 by atucci            #+#    #+#             */
/*   Updated: 2023/06/01 10:44:24 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

/*
** This code defines a struct called t_stack which is used to represent a node in
** a linked list for a stack of integers.
*/

typedef struct s_stack
{
    int nbr;               // The integer value stored in the node
    int index;             // The index of the node in the list
    struct s_stack *next;   // A pointer to the next node in the list
    struct s_stack *prev;   // A pointer to the previous node in the list
} t_stack;
/* matt isidore advices
typedef struct s_stack
{
	int	size;
	t_node	*node;
}   t_stack

t_stack	*stack_a;
*/
int		len_stack_a(char *str);
int		correct_char(char *str);
int		check_stack(t_stack *stk);
t_stack	*split_num_in_stack(char *number);
t_stack	*fill_stack(int ac, char **av);
void	pa(t_stack **a, t_stack **b, int j);
void	pb(t_stack **stack_a, t_stack **stack_b, int j);
void	sa(t_stack **a, int j);
void	sb(t_stack **stack_b, int j);
void	ss(t_stack *stk);
void	ra(t_stack **stk, int j);
void	rb(t_stack *stk);
void	rr(t_stack *stk);
void	rra(t_stack **stk, int j);
void	rrb(t_stack *stk);
void	sort_due(t_stack **stk);
void	sort_tre(t_stack **stk);
void	print_stack(t_stack **stk);
void	sort_stack(t_stack **stk);
int		is_B_sorted(t_stack *stk);
int		is_sorted(t_stack *stk);
int		find_small(t_stack *stk, int *pos);
void	testa_toro(t_stack **stack);
int		get_list_length(t_stack *head);
t_stack	*ft_lstlasty(t_stack *lst);
void update_indexes(t_stack *stack);
int get_moves_to_top(t_stack *stack, int index);
int is_empty(t_stack **stack);
int		has_repetitions(t_stack *stack);
int	find_mid_value(int *array_int, int size);
void	quick_sort(t_stack **stack_a);
t_stack *list_copy(t_stack **stack_a);
t_stack *sort_the_list(t_stack **stack_a);
int get_mid_value(t_stack *head);
#endif
