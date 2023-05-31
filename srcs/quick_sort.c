/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:34:02 by atucci            #+#    #+#             */
/*   Updated: 2023/05/31 14:03:49 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/push_swap.h"

int	find_mid_value(t_stack *stack_a)
{
    int size;
    int mid_value;
    int mid_position;
    int i;
    t_stack *current_node;

    size = get_list_length(stack_a);
    current_node = stack_a;
    mid_position = size / 2;
    i = 0;
    while (i < mid_position)
    {
        current_node = current_node->next;
        i++;
    }
    mid_value = current_node->nbr;
    return(mid_value);
}

void	quick_sort(t_stack **stack_a)
{
	int		middle;
	t_stack	**stack_b;
    int     len_a;
    int     len_b;
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	
    *stack_b = NULL;
    middle = find_mid_value(*stack_a);
	len_a = get_list_length(*stack_a);
    len_b = 0;

    int count = 0;
    while (count < 3) // i need to change this condition
    {
        if ((*stack_a)->index == 0 && (*stack_a)->nbr < middle)
        {
            pb(stack_a, stack_b, 0);
            update_indexes(*stack_a);
            update_indexes(*stack_b);
            ft_printf("+++++\nstack b\n");
            print_stack(stack_b);
            ft_printf("+++++\nstack a\n");
            print_stack(stack_a);
        }
        else
        {
             ra(stack_a, 0);
             update_indexes(*stack_a);
            ft_printf("+++++\nstack a\n");
            print_stack(stack_a);
            update_indexes(*stack_b);
        }
    len_b = get_list_length(*stack_b);
    len_a = get_list_length(*stack_a);
    update_indexes(*stack_a);
    update_indexes(*stack_b);
    count++;
    }
    // for now lets do this...
    update_indexes(*stack_a);
    update_indexes(*stack_b);
    ft_printf("------------------------\nstack a\n");
    print_stack(stack_a);
    ft_printf("------------------------\nstack b\n");
    print_stack(stack_b); 
    return ;
}