/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stack.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 18:05:33 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/23 20:16:58 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

t_stack			*new_stack(t_grid *grid)
{
	t_stack		*stack;

	if (!(stack = (t_stack*)ft_memalloc(sizeof(t_stack))))
		return (0);
	stack->grid = grid;
	return (stack);
}

void			stack_destroy(t_stack *stack)
{
	grid_destroy(stack->grid);
	ft_memdel((void**)&stack);
	return ;
}

void			stack_del(t_stack **stack)
{
	t_stack		*next;
	
	while (*stack)
	{
		next = (*stack)->next;
		stack_destroy(*stack);
		*stack = next;
	}
	return ;
}

void			stack_delone(t_stack **stack, t_stack *del)
{
	t_stack		*swap;

	swap = (*stack)->next;
	while (swap)
	{
		if (swap == del)
		{
			if ((*stack)->prev == swap)
				(*stack)->prev = swap->prev;
			swap->prev->next = swap->next;
			ft_memdel((void**)&swap);
		}
		swap = swap->next;
	}
	return ;
}

void			stack_add(t_stack **stack, t_stack *new_stack)
{
	new_stack->prev = *stack;
	new_stack->next = *stack;
	(*stack)->prev = new_stack;
	*stack = new_stack;
	return ;
}