/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/22 17:33:22 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/26 04:48:48 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

void			draw_stack(t_stack **stack, t_stack *marker)
{
	int			color;
	t_stack		*cur;

	cur = *stack;
	while (cur)
	{
		if (marker == cur)
			color = 0x002B7EB0;
		else
			color = 0x002D4372;
		grid_draw(cur->grid, color);
		cur = cur->next;
	}
	return ;
}

void			marker_next(t_stack *marker)
{
	marker = marker->next;
	return ;
}

void			marker_prev(t_stack *marker)
{
	marker = marker->prev;
	return ;
}
