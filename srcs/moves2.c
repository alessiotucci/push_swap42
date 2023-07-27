/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:37:30 by atucci            #+#    #+#             */
/*   Updated: 2023/07/27 18:47:16 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus/libft.h"
#include "../incl/push_swap.h"

/*
** Finds and returns the last node (tail) of a doubly linked list.
** The function traverses the list starting from the given node 'lst'
** and follows the 'prev' pointers until it reaches the last node.
** Returns a pointer to the last node in the list.
** If the input parameter 'lst' is NULL (empty list), it returns NULL.
*/
t_stack	*ft_lstlasty(t_stack *lst)
{
	if (lst == NULL)   // Check if the input list is empty (NULL).
		return (NULL); // If so, return NULL.

	// Traverse the list backward by following the 'prev' pointers until the last node is reached.
	while (lst->prev != NULL)
		lst = lst->prev;

	return (lst); // Return a pointer to the last node (tail) of the list.
}


void	ra(t_stack **a, int j)
{
	t_stack	*tmp;
	t_stack	*first;

	if (!*a || !(*a)->next)
		return ;
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

void	rb(t_stack **b, int j)
{
	t_stack	*tmp;
	t_stack	*first;

	if (!*b || !(*b)->next)
		return ;
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

void	rrb(t_stack **b, int j)
{
	t_stack	*tmp;
	int		i;

	if (!*b || !(*b)->next)
		return ;
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

