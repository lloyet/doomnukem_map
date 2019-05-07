/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_utils.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/07 10:57:49 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/07 22:25:14 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/doom_map.h"

void				event_draw_tmp(t_layer *l, int x, int y)
{
	t_vertex		*v;
	t_vertex		*v_shape;
	t_vertex		*begin;

	v = new_vertex(x, y);
	if (l->s_tmp && l->mode)
	{
		begin = (t_vertex*)l->s_tmp->vertex->begin->content;
		if ((v_shape = shape_has_vertex(l->s_tmp, v)) && v_shape == begin)
		{
			shape_add(l->s_tmp, v_shape);
			l->mode = 0;
		}
		else
			shape_add(l->s_tmp, v);
	}
	if (l->mode && !l->s_tmp)
		if (!(layer_has_vertex(l, v)))
			l->s_tmp = new_shape(v);
	if (!l->mode && l->s_tmp)
		if ((l->v_tmp = shape_has_vertex(l->s_tmp, v)))
			ft_putstr("vertex_move\n");
	ft_putstr("mouseLeft Rising\n");
	return ;
}

void				event_delete_tmp(t_layer *l)
{
	if (l->is_draw && l->s_tmp)
	{
		if (l->s_tmp->vertex->n < 2)
		{
			shape_destroy(l->s_tmp);
			l->s_tmp = 0;
		}
		else
			shape_remove(l->s_tmp);
	}
	return ;
}
