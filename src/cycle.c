/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cycle.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/26 21:39:51 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/27 06:55:01 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

t_cycle			*new_cycle(t_grid *grid)
{
	t_cycle		*cycle;

	if (!(cycle = (t_cycle*)ft_memalloc(sizeof(t_cycle))))
		return (0);
	cycle->next = cycle;
	cycle->prev = cycle;
	cycle->grid = grid;
	return (cycle);
}

void			cycle_destroy(t_cycle *cycle)
{
	grid_destroy(cycle->grid);
	ft_memdel((void**)&cycle);
	return ;
}

void			cycle_delall(t_cycle **acycle)
{
	t_cycle		*cur;
	
	cur = (*acycle)->next;
	while (cur)
	{
		cycle_destroy(cur);
		cur = cur->next;
		if (cur == *acycle)
			break;
	}
	cycle_destroy(*acycle);
	return ;
}

void			cycle_iter(t_cycle **acycle, void (*f)(t_cycle *elem))
{
	t_cycle		*cur;

	cur = *acycle;
	while (cur)
	{
		(*f)(cur);
		cur = cur->next;
		if (cur == *acycle)
			break;
	}
	return ;
}

int				cycle_len(t_cycle **acycle)
{
	int			size;
	t_cycle		*cur;

	size = 0;
	cur = *acycle;
	while (cur)
	{
		size++;
		cur = cur->next;
		if (cur == *acycle)
			break;
	}
	return (size);
}

int				cycle_index(t_cycle **acycle, t_cycle **marker)
{
	int			index;
	t_cycle		*cur;

	index = 0;
	cur = *acycle;
	while (cur)
	{
		index++;
		cur = cur->next;
		if (cur == *acycle || cur == *marker)
			break;
	}
	return (index);
}

void			cycle_delone(t_cycle **acycle, t_cycle **marker)
{
	t_cycle		*del;

	del = *marker;
	if (cycle_index(acycle, marker) > 1)
	{
		(*marker)->next->prev = (*marker)->prev;
		(*marker)->prev->next = (*marker)->next;
		*marker = (*marker)->prev;
		cycle_destroy(del);
	}
	return ;
}

void			cycle_insert(t_cycle **marker, t_cycle *new_cycle)
{
	new_cycle->prev = *marker;
	new_cycle->next = (*marker)->next;
	(*marker)->next->prev = new_cycle;
	(*marker)->next = new_cycle;
	marker = &new_cycle;
	return ;
}

void			cycle_draw(t_cycle **acycle, t_cycle **marker)
{
	int			color;
	t_cycle		*cur;

	cur = *acycle;
	while (cur)
	{
		if (*marker == cur)
			color = CLR_LAYER;
		else
			color = CLR_SHADOW;
		grid_draw(cur->grid, color);
		cur = cur->next;
		if (cur == *acycle)
			break;
	}
	return ;
}
