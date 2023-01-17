#include "push_swap.h"

stack *push_swap(stack *a)
{
	stack b;
	int length_a;

	length_a = stack_length(*a) / 2;
	b = new_stack();
	sort(a, &b);
	return (a);
}

void	sort(stack *a, stack *b)
{
	int small;
	int index;
	stack a_holder;

	while (!stack_is_empty(*a))
	{
		small = INT_MAX;
		a_holder = *a;
		index = 0;
		while (!stack_is_empty(a_holder))
		{
			if (a_holder->value < small)
				small = a_holder->value;
			a_holder = a_holder->next;
		}
		a_holder = *a;
		while (a_holder->value != small)
		{
			a_holder = a_holder->next;
			index++;
		}
		if (index > stack_length(*a) / 2)
			move_small(a, stack_length(*a) - index, rotate_back_a);
		else
			move_small(a, index, rotate_a);
		push_b(a, b);
	}
	while (!stack_is_empty(*b))
		push_a(a, b);
}

int	first(stack stk)
{
	return ((stk)->value);
}

int second(stack stk)
{
	return ((stk)->next->value);
}

int last(stack stk)
{
	return ((*tail_stack(&stk))->value);
}

void move_small(stack *a, int index, void (*rotate)(stack *a))
{
	int i;

	i = 0;
	while (i < index)
	{
		(*rotate)(a);
		i++;
	}
}

int check_double(char **ss)
{
	int i;
	int j;

	i = 1;
	while (ss[i])
	{
		j = i + 1;
		while (ss[j])
		{
			if ((ft_strncmp(ss[i], ss[j], ft_strlen(ss[i])) == 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int main(int argv, char **argc)
{
	stack stk;
	int i;
	int nbr;
	int j;
	char *ss;

	i = argv;
	stk = new_stack();
	if (check_double(argc) == 0)
		{
			ft_printf("ERROiR");
			return (0);
		}
	while (i > 1)
	{
		j = 0;
		while (ft_isdigit(argc[i - 1][j]))
			j++;
		if (ft_strlen(argc[i - 1]) != j)
		{
			ft_printf("ERROoR");
			return (0);
		}
		nbr = atoi(argc[i - 1]);
		if (nbr)
			stk = push_stack(stk, nbr);
		i--;
	}
	// print_stack(stk);
	// print_stack(stk);
	// stk = pop_stack(stk);
	// stk = clear_stack(stk);
	// print_stack(stk);
	push_swap(&stk);
	// print_stack(stk);
	
	// print_stack(stk);
}