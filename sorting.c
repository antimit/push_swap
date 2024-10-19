/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:11:09 by antimit           #+#    #+#             */
/*   Updated: 2024/10/19 19:30:19 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*biggest(t_stack_node *a)
{
	t_stack_node	*result;
	int				biggest_value;

	if (!a)
		return (NULL);
	result = a;
	biggest_value = a->value;
	while (a)
	{
		if (a->value > biggest_value)
		{
			result = a;
			biggest_value = a->value;
		}
		a = a->next;
	}
	return (result);
}

t_stack_node	*smallest(t_stack_node *a)
{
	t_stack_node	*result;
	int				smallest_value;

	if (!a)
		return (NULL);
	result = a;
	smallest_value = a->value;
	while (a)
	{
		if (a->value < smallest_value)
		{
			result = a;
			smallest_value = a->value;
		}
		a = a->next;
	}
	return (result);
}

void	tiny_sort(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = biggest(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	handle_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, smallest(*a), 'a');
		pb(b, a);
	}
}
