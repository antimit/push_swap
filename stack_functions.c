/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:11:17 by antimit           #+#    #+#             */
/*   Updated: 2024/10/19 19:35:58 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **lst)
{
	int				len;
	t_stack_node	*last;
	t_stack_node	*temp;

	len = stack_len(*lst);
	if (!lst || !*lst || len == 1)
		return ;
	last = find_last_element(*lst);
	temp = *lst;
	*lst = temp->next;
	temp->next->prev = NULL;
	temp->next = NULL;
	temp->prev = last;
	last->next = temp;
}

void	rrotate(t_stack_node **lst)
{
	int				len;
	t_stack_node	*last;
	t_stack_node	*temp;

	len = stack_len(*lst);
	if (!lst || !*lst || len == 1)
		return ;
	last = find_last_element(*lst);
	temp = *lst;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = temp;
	temp->prev = last;
	*lst = last;
}
