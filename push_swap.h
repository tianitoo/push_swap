/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:09:10 by hnait             #+#    #+#             */
/*   Updated: 2023/02/16 13:37:46 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PUSH_SWAP__H__
# define __PUSH_SWAP__H__
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef enum
{
	False,
	True
} Bool;

typedef struct element
{
	int value;
	struct element *next;
}element, *stack;

stack	new_stack();
void	clear_stack(stack *stk);
int		stack_length(stack stk);
int		top_stack(stack stk);
void	pop_stack(stack *stk);
void	print_stack(stack stk);
stack	push_stack(stack stk, int i);
stack	*push_swap(stack *a);
void	push(stack *a, stack *b, char stk_name);
stack	swap(stack stk, char stk_name);
void	rotate(stack *a, char stk_name);
void	rr(stack *a, stack *b);
void	rotate_back(stack *a, char stk_name);
stack	*tail_stack(stack *stk);
int		biggest_in_stack(stack stk);
stack	clone_stack(stack *stk);
Bool	stack_is_empty(stack stk);
void	sort(stack *a, stack *b);
int		first(stack stk);
stack	lis(stack *stk);
void	five(stack *a, stack *b);
int		second(stack stk);
Bool	stack_is_sorted(stack stk);
char	**split(char *s);
void	rrr(stack *a, stack *b);
stack	element_by_index(stack stk, int index);
int		check_double(stack stk, int i);
void	three(stack *stk, char stk_name);
int		last(stack stk);
stack	next(stack stk);
int		find_small(stack stk);
Bool	exists_in_stack(stack stk, int number);
int		index_of_bigger(stack stk, int i);
int		number_by_index(stack stk, int index);
void	more(stack *a, stack *b);
void	move_small(stack *a, char name);
stack	sub(stack stk);

 
#endif