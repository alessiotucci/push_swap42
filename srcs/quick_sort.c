/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:34:02 by atucci            #+#    #+#             */
/*   Updated: 2023/06/01 10:45:34 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../incl/push_swap.h"

// list copy (t_stack **stack_a)

t_stack *list_copy(t_stack **stack_a)
{
    t_stack *current = *stack_a;
    t_stack *new_list = NULL;
    t_stack *new_tail = NULL;

    // Iterate over the original list
    while (current != NULL)
    {
        // Create a new node
        t_stack *new_node = malloc(sizeof(t_stack));
        if (new_node == NULL)
        {
            // Error handling for memory allocation failure
            printf("Error: Memory allocation failed\n");
            // Clean up the already copied list
            while (new_list != NULL)
            {
                t_stack *temp = new_list;
                new_list = new_list->next;
                free(temp);
            }
            return NULL;
        }
        // Copy the data from the original node to the new node
        new_node->nbr = current->nbr;
        new_node->next = NULL;
        // Append the new node to the new list
        if (new_list == NULL)
        {
            // If the new list is empty, set the new node as the head
            new_list = new_node;
			new_tail = new_node;
        }
        else
        {
            // Otherwise, append the new node to the tail of the new list
			new_tail->next = new_node;
			new_tail = new_node;
        }
        // Move to the next node in the original list
        current = current->next;
    }
    return (new_list);
} 
// sort list  copy(int *array, int size)
t_stack *sort_the_list(t_stack **stack_a)
{
    // Check if the list is empty or has only one element
    if (*stack_a == NULL || (*stack_a)->next == NULL)
    {
        return *stack_a;
    }
    // Split the list into two halves
    t_stack *slow = *stack_a;
    t_stack *fast = (*stack_a)->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    t_stack *second_half = slow->next;
    slow->next = NULL;
    // Recursively sort the two halves
    t_stack *sorted_first_half = sort_the_list(stack_a);
    t_stack *sorted_second_half = sort_the_list(&second_half);
    // Merge the sorted halves
    t_stack dummy;
    t_stack *current = &dummy;
    while (sorted_first_half != NULL && sorted_second_half != NULL)
    {
        if (sorted_first_half->nbr <= sorted_second_half->nbr)
        {
            current->next = sorted_first_half;
            sorted_first_half = sorted_first_half->next;
        }
        else
        {
            current->next = sorted_second_half;
            sorted_second_half = sorted_second_half->next;
        }
        current = current->next;
    }
    // Append the remaining nodes
    if (sorted_first_half != NULL)
    {
        current->next = sorted_first_half;
    }
    else if (sorted_second_half != NULL)
    {
        current->next = sorted_second_half;
    }
    // Return the head of the merged list
    return dummy.next;
} 



//	find_mid_value(int *array_int, int size)
	int get_mid_value(t_stack *head)
{
    int length = get_list_length(head);
    int mid_index = length / 2;

    t_stack *current = head;
    int	i = 0;
	while (i < mid_index)
    {
        current = current->next;
    	i++;
	}

    return current->nbr;
}

void	quick_sort(t_stack **stack_a)
{
	int		middle;
	t_stack	**stack_b;
    int     len_a;
    int     len_b;
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	
    *stack_b = NULL;
    middle =  0 ;// this is just temporary
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
