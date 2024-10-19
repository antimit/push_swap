/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:12:32 by antimit           #+#    #+#             */
/*   Updated: 2024/10/19 19:12:33 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*newnode;
	t_stack_node	*temp;

	if (!*src)
		return ;
	newnode = *src;
	*src = newnode->next;
	if (newnode->next)
		newnode->next->prev = NULL;
	if (!*dest)
	{
		newnode->next = NULL;
		*dest = newnode;
	}
	else
	{
		temp = *dest;
		newnode->next = temp;
		temp->prev = newnode;
		*dest = newnode;
	}
}

void	swap(t_stack_node **lst)
{
	t_stack_node	*temp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	temp = (*lst)->next;
	(*lst)->next = temp->next;
	if (temp->next)
		temp->next->prev = *lst;
	temp->next = *lst;
	(*lst)->prev = temp;
	temp->prev = NULL;
	*lst = temp;
}

int	stack_len(t_stack_node *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

int	stack_sorted(t_stack_node *lst)
{
	while (lst->next)
	{
		if (lst->value > lst->next->value)
		{
			return (0);
		}
		lst = lst->next;
	}
	return (1);
}

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
