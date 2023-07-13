/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:46:30 by atucci            #+#    #+#             */
/*   Updated: 2023/06/26 17:37:08 by atucci           ###   ########.fr       */
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
	long			nbr;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;
int		len_stack_a(char *str);
int		correct_char(char *str);
int		check_stack(t_stack *stk);
t_stack	*split_num_in_stack(char *number);
t_stack	*fill_stack(int ac, char **av);
t_stack	*ft_lstlasty(t_stack *lst);
void	pa(t_stack **a, t_stack **b, int j);
void	pb(t_stack **stack_a, t_stack **stack_b, int j);
void	sa(t_stack **a, int j);
void	sb(t_stack **stack_b, int j);
void	ss(t_stack *stk);
void	ra(t_stack **stk, int j);
void	rb(t_stack **stk, int j);
void	rr(t_stack *stk);
void	rra(t_stack **stk, int j);
void	rrb(t_stack **stk, int j);
void	sort_due(t_stack **stk);
void	sort_tre(t_stack **stk);
void	print_stack(t_stack **stk);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
int		is_B_sorted(t_stack *stk);
int		is_sorted(t_stack *stk);
int		find_big(t_stack **stk, int *pos);
int		find_small(t_stack **stack_a, int *pos);
int		get_list_length(t_stack *head);
void	update_indexes(t_stack *stack);
//void	update_indexes(t_stack *list1, t_stack *list2);
int		get_moves_to_top(t_stack *stack, int index);
int		is_empty(t_stack **stack);
int		has_repetitions(t_stack *stack);
t_stack	*create_new_node(char *number, int index);
t_stack	*add_new_nody(int number, int index);
void	add_node_to_stack(t_stack **stack, t_stack *new_node);
void	set_index(t_stack **new_node, t_stack *stack);
int		find_mid_value(t_stack *stack_a);
void	quick_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_list(t_stack **head);
void	swap(t_stack *a, t_stack *b);
void	sort_the_list(t_stack **stack_a);
int		get_mid_value(t_stack *head);
void	check_and_push(t_stack **stack_a, t_stack **stack_b, int middle);
void	selection_sort_stack_b(t_stack **stack_a, t_stack **stack_b);
t_stack	*initialize_stack_b(void);
int		process_arguments(char *arg, t_stack **stack);
int		get_medd_value(t_stack *head);
void	push_to_stack_b(t_stack **stack_a, t_stack **stack_b);
void	move_pivot_to_top(t_stack **a, t_stack **b, int pos, int moves);
int		free_lists(t_stack *list_a, t_stack *list_b);
void	process_stack_b(t_stack **stack_a, t_stack **stack_b);
int		update_indexes_and_get_length(t_stack *head);
int		free_split(char **tab);
long	ft_atoi_plus(const char *str);
int		print_exit(void);
#endif
