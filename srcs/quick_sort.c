/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:34:02 by atucci            #+#    #+#             */
/*   Updated: 2023/05/31 15:31:04 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/push_swap.h"

int *from_list_to_array(t_stack **stack_a)
{
    int size = get_list_length(*stack_a);
    int *unsorted_array = malloc(size * sizeof(int));
    t_stack *current = *stack_a;
    int i = 0;

    // Store the values of the linked list in an array
    while (current != NULL)
    {
        unsorted_array[i] = current->nbr;
        current = current->next;
        i++;
    }

    return unsorted_array;
}
int *sorting_array(int *array, int size)
{
    int sorted = 0;
    int i = 0;
    while (!sorted)
    {
        sorted = 1;
        while (i < size - 1)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                sorted = 0;
            }
        i++;
        }
        size--;
    }

    return array;
}



int	find_mid_value(int *array_int, int size)
{
    int mid_value;

    mid_value = array_int[size/2];

    ft_printf("this is  mid %d\n", mid_value);
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
    middle =  find_mid_value(sorting_array(from_list_to_array(stack_a), get_list_length(*stack_a)), get_list_length(*stack_a));
	len_a = get_list_length(*stack_a);
    len_b = 0;

    int count = 0;
    while (count <= (len_a / 2)) // i need to change this condition
    {
        if ((*stack_a)->index == 0 && (*stack_a)->nbr < middle)
        {
            pb(stack_a, stack_b, 0);
            update_indexes(*stack_a);
            update_indexes(*stack_b);
            ft_printf("+++++\nSTACK B\n");
            print_stack(stack_b);
           // ft_printf("+++++\nstack a\n");
           // print_stack(stack_a);
        }
        else
        {
             ra(stack_a, 0);
             update_indexes(*stack_a);
            ft_printf("+++++\nSTACK A\n");
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