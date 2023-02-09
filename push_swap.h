/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:09:10 by hnait             #+#    #+#             */
/*   Updated: 2023/02/09 15:47:58 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PUSH_SWAP__H__
# define __PUSH_SWAP__H__
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

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
stack	clear_stack(stack stk);
int		stack_length(stack stk);
int		top_stack(stack stk);
void	pop_stack(stack *stk);
void	print_stack(stack stk);
stack	push_stack(stack stk, int i);
stack	*push_swap(stack *a);
void	push(stack *a, stack *b, char stk_name);
stack	swap(stack stk, char stk_name);
void	rotate(stack *a, char stk_name);
void	rotate_back(stack *a, char stk_name);
stack	*tail_stack(stack *stk);
stack	clone_stack(stack stk);
Bool	stack_is_empty(stack stk);
void	sort(stack *a, stack *b);
int		first(stack stk);
void	five(stack *a, stack *b);
int		second(stack stk);
Bool	stack_is_sorted(stack stk);
char	**split(char *s);
int		check_double(char **ss);
void	three(stack *stk, char stk_name);
int		last(stack stk);
int		find_small(stack stk);
int		index_of_bigger(stack stk, int i);
int		number_by_index(stack stk, int index);
void	more(stack *a, stack *b);
void	move_small(stack *a, int index, char name, void (*rotate)(stack *a, char stk_name));
 
#endif