#include "push_swap.h"

stack *push_swap(stack *a)
{
	stack b;
	int length_a;

	length_a = stack_length(*a);
	b = new_stack();
	sort(a, &b);
	return (a);
}

void	sort(stack *a, stack *b)
{
	if (stack_length(*a) <= 3)
		three(a, 'a');
	else if (stack_length(*a) <= 5)
		five(a, b);

	// else if (stack_length(*a) <= 100)
	// 	hundred(*a, *b);
	// else if (stack_length(*a) > 100)
	// 	more(*a, *b);
}

void	three(stack *stk, char stk_name)
{
	while (!stack_is_sorted(*stk))
	{
		if (first(*stk) > second(*stk) && first(*stk) > last(*stk))
			rotate(stk, stk_name);
		if (second(*stk) > first(*stk) && second(*stk) > last(*stk))
			rotate_back(stk, stk_name);
		if (!stack_is_sorted(*stk))
			*stk = swap(*stk, stk_name);
	}
}


int isbigger(stack stk, int i)
{

	while (stk->next && stk->value < i)
	{
		stk = stk->next;
	}
	return (stk->value);
}

int find_small(stack stk)
{
	int small = INT_MAX;
	int small_index;
	int i;

	i = 0;
	while (!stack_is_empty(stk))
	{
		if (small > stk->value)
		{
			small = stk->value;
			small_index = i;
		}
		stk = stk->next;
		i++;

	}
	return (small_index);
}

void	five(stack *a, stack *b)
{
	int bigger;

	push(a, b, 'b');
	push(a, b, 'b');
	three(a, 'a');
	three(b, 'b');
	while (!stack_is_empty(*b))
	{
		bigger = isbigger(*a, first(*b));
		while (bigger != first(*a))
		{
			if (bigger > stack_length(*a) / 2 && bigger != 1)
				rotate(a, 'a');
			else
				rotate_back(a,'a');
		}
		if (first(*a) < first(*b))
			rotate(a, 'a');
		
		push(a, b, 'a');
	}
	
	while (!stack_is_sorted(*a))
	{
		if (find_small(*a) < stack_length(*a) / 2)
			move_small(a, find_small(*a), 'a', rotate_back);
		else
			move_small(a, find_small(*a), 'a', rotate);
	}

}

int	first(stack stk)
{
	return ((stk)->value);
}

int second(stack stk)
{
	return (stk->next->value);
}

int last(stack stk)
{
	return ((*tail_stack(&stk))->value);
}

void move_small(stack *a,
				int index,
				char name,
				void (*rotate)(stack *a,
				char stk_name))
{
	int i;

	i = 0;
	while (i < index)
	{
		(*rotate)(a, name);
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
			if ((ft_strncmp(ss[i], ss[j], ft_strlen(ss[i])) == 0) 
					&& ft_strlen(ss[i]) == ft_strlen(ss[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char **split(char *s)
{
	int i;
	char **ss;
	size_t	j;

	i = 0;
	ss = ft_split(s, ' ');
	while (ss[i])
	{
		j = 0;
		while (ss[i][j])
		{
			if (!ft_isdigit(ss[i][j]))
			{
				ft_printf("ERRO6R");
				return (0);
			}
			j++;
		}
		// ft_printf("|%s|\n", ss[i]);
		if (ft_strlen(ss[i]) != j)
		{
			ft_printf("ERROoR");
			return (0);
		}
		i++;
	}
			// ft_printf("test\n");
	return (ss);
}

Bool stack_is_sorted(stack stk)
{
	while (!stack_is_empty(stk) && stack_length(stk) > 1)
	{
		if(first(stk) > second(stk))
			return (False);
		stk = stk->next;
	}
	return (True);
}

int main(int argv, char **argc)
{
	stack stk;
	int i;
	int nbr;
	char **ss;

	i = argv - 1;
	stk = new_stack();
	if (check_double(argc) == 0)
	{
		ft_printf("ERROiR");
		return (0);
	}
	while (i > 0)
	{
		ss = split(argc[i]);
		if (!ss)
			return (0);
		
		while (*ss)
		{
			nbr = ft_atoi(*ss);
			if (nbr)
				stk = push_stack(stk, nbr);
			ss++;
		}
		i--;
	}

	// print_stack(stk);
	// stk = pop_stack(stk);
	// stk = clear_stack(stk);
	// print_stack(stk);
	// print_stack(stk);
	if(stack_length(stk) > 1 && !stack_is_sorted(stk))
		push_swap(&stk);
	// print_stack(stk);
	// print_stack(stk);
	// print_stack(stk);
	
}