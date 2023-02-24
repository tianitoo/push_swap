/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:09:10 by hnait             #+#    #+#             */
/*   Updated: 2023/02/24 20:32:06 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef enum s_bool
{
	False,
	True
}t_bool;

typedef struct s_element
{
	int					value;
	struct s_element	*next;
}t_element,	*t_stack;

void	clear_stack(t_stack *stk);
int		stack_length(t_stack stk);
void	pop_stack(t_stack *stk);
void	print_stack(t_stack stk);
t_stack	push_stack(t_stack stk, int i);
t_stack	*push_swap(t_stack *a);
void	push(t_stack *a, t_stack *b, char stk_name);
t_stack	swap(t_stack stk, char stk_name);
void	rotate(t_stack *a, char stk_name);
void	rr(t_stack *a, t_stack *b);
void	rotate_back(t_stack *a, char stk_name);
t_stack	*tail_stack(t_stack *stk);
int		biggest_in_stack(t_stack stk);
t_stack	clone_stack(t_stack *stk);
t_bool	stack_is_empty(t_stack stk);
void	sort(t_stack *a, t_stack *b);
int		first(t_stack stk);
t_stack	lis(t_stack *stk);
void	five(t_stack *a, t_stack *b);
int		second(t_stack stk);
int		number_of_instructions(t_stack *a, t_stack b, int index);
t_bool	stack_is_sorted(t_stack stk);
char	**split(char *s);
void	rrr(t_stack *a, t_stack *b);
t_stack	element_by_index(t_stack stk, int index);
int		check_double(t_stack stk, int i);
void	three(t_stack *stk, char stk_name);
int		last(t_stack stk);
t_stack	next(t_stack stk);
int		find_small_index(t_stack stk);
void	move(t_stack *a, t_stack *b, int index);
t_bool	exists_in_stack(t_stack stk, int number);
int		index_of_bigger(t_stack stk, int i);
int		number_by_index(t_stack stk, int index);
void	more(t_stack *a, t_stack *b);
void	move_small(t_stack *a, char name);
t_stack	sub(t_stack stk);
#endif