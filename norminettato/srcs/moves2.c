/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:37:30 by atucci            #+#    #+#             */
/*   Updated: 2023/06/26 17:55:25 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus/libft.h"
#include "../incl/push_swap.h"

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

t_stack	*ft_lstlasty(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->prev != NULL)
		lst = lst->prev;
	return (lst);
}
