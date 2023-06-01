/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:34:02 by atucci            #+#    #+#             */
/*   Updated: 2023/06/01 12:36:16 by atucci           ###   ########.fr       */
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
// small helper function 
void swap(t_stack *a, t_stack *b)
{
    int temp = a->nbr;
    a->nbr = b->nbr;
    b->nbr = temp;
}
// sort list  copy(int *array, int size)

void sort_the_list(t_stack **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    int swapped;
    t_stack *current;
    t_stack *tail = NULL;

    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        current = *head;

        while (current->next != tail)
        {
            if (current->nbr > current->next->nbr)
            {
                swap(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        tail = current;
    }
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
    ///////// I need to find the middle point each time for the new list (right?)
    t_stack *copy = list_copy(stack_a);
    sort_the_list(&copy);
    middle = get_mid_value(copy);
    ft_printf("the middle value is [%d]\n", middle);
    //////// I could create an other function that just copy, sort and give me the mid point back (right?)

	len_a = get_list_length(*stack_a);
    len_b = 0;

    //int count = 0;
    while (len_b < len_a) // i need to change this condition
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
    //count++;
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
