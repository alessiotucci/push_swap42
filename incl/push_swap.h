/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:46:30 by atucci            #+#    #+#             */
/*   Updated: 2023/05/02 10:43:42 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	la;
	int	lb;
}		t_stack;

int		len_stack_a(char *str);
int		correct_char(char *str);
int		check_stack(t_stack *stk);
void	split_num_in_stack(char *number, t_stack *stack);
void	fill_stack(int ac, char *av[], t_stack *stack);
void	pa(t_stack *stk);
void	pb(t_stack *stk);
void	sa(t_stack *stk);
void	sb(t_stack *stk);
void	ss(t_stack *stk);
void	ra(t_stack *stk);
void	rb(t_stack *stk);
void	rr(t_stack *stk);
void	rra(t_stack *stk);
void	rrb(t_stack *stk);
void	sort_due(t_stack *stk);
void	sort_tre(t_stack *stk);
void	print_stack(t_stack *stk);
void	sort_stack(t_stack *stk);
int		is_sorted(t_stack *stk);
int		find_small(t_stack *stk, int *pos);
#endif
