/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:40:12 by antimit           #+#    #+#             */
/*   Updated: 2024/10/19 19:28:56 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// stack
void					push(t_stack_node **dest, t_stack_node **src);
int						stack_len(t_stack_node *lst);
int						stack_sorted(t_stack_node *lst);
t_stack_node			*return_cheapest(t_stack_node *stack);

// stack functions
void					rotate(t_stack_node **lst);
void					rrotate(t_stack_node **lst);
void					swap(t_stack_node **lst);

// sorting
void					tiny_sort(t_stack_node **a);
t_stack_node			*biggest(t_stack_node *a);
t_stack_node			*smallest(t_stack_node *a);
void					handle_five(t_stack_node **a, t_stack_node **b);

// Push_swap
void					finish_rotation(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);
void					push_swap(t_stack_node **a, t_stack_node **b);

// stack main functions
void					sa(t_stack_node **a);
void					sb(t_stack_node **b);
void					pa(t_stack_node **a, t_stack_node **b);
void					pb(t_stack_node **b, t_stack_node **a);
void					ra(t_stack_node **a);
void					rb(t_stack_node **b);
void					rra(t_stack_node **a);
void					rrb(t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);
void					rrr(t_stack_node **a, t_stack_node **b);

// list
void					add_element(t_stack_node **lst, int data);
void					print_list(t_stack_node *lst);
void					print_list_reverse(t_stack_node *lst);
t_stack_node			*find_last_element(t_stack_node *lst);

// Node initialization
void					set_current_position(t_stack_node *stack);
void					set_target_node(t_stack_node *a, t_stack_node *b);
void					set_price(t_stack_node *a, t_stack_node *b);
void					set_cheapest(t_stack_node *b);
void					init_nodes(t_stack_node *a, t_stack_node *b);

// Error handlers
void					free_matrix(char **argv);
void					free_stack(t_stack_node **stack);
void					error_free(t_stack_node **a, char **argv,
							bool flag_argc_2);
int						error_syntax(char *str_nbr);
int						error_repetition(t_stack_node *a, int nbr);

// ft_split
void					free_split(char **split, size_t i);
int						skip_chars(const char *str, int i, char sep, int mode);
size_t					count_words(const char *str, char sep);
char					*ft_word(const char *str, char sep);
char					**init_result(const char *s, char c);
int						process_words(char **result, const char *s, char c);
char					**ft_split(const char *s, char c);

#endif
