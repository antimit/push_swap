/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:38:25 by antimit           #+#    #+#             */
/*   Updated: 2024/10/19 19:38:31 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_element(t_stack_node **lst, int data)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!lst)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = data;
	if (!*lst)
	{
		*lst = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_element(*lst);
		last_node->next = node;
		node->prev = last_node;
	}
}

// void	print_list(t_stack_node *lst)
// {
// 	while (lst)
// 	{
// 		printf("%d\n", lst->value);
// 		lst = lst->next;
// 	}
// }

t_stack_node	*find_last_element(t_stack_node *lst)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
