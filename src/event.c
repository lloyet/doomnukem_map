/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/22 17:52:25 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/07 00:10:36 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/doom_map.h"

static void			event_layer_iter(t_engine *e)
{
	t_keyboard 		*k;

	k = e->keyboard;
	if (key_is_rising(k, MOUSE_SCROLL_UP))
	{
		if (key_is_pressed(k, KEY_CTRL_LEFT))
			gui_next(e->gui);
		else
			ft_putstr("Zoom In\n");
	}
	else if (key_is_rising(k, MOUSE_SCROLL_DOWN))
	{
		if (key_is_pressed(k, KEY_CTRL_LEFT))
			gui_prev(e->gui);
		else
			ft_putstr("Zoom Out\n");
	}
	return ;
}

static void			event_layer_draw(t_engine *e)
{
	t_vertex		*v;
	t_layer			*l;
	t_keyboard		*k;

	l = (t_layer*)e->gui->iterator->content;
	if (l->is_draw)
	{
		k = e->keyboard;
		if (key_is_pressed(k, MOUSE_RIGHT))
			ft_putstr("mouseRight\n");
		if (key_is_rising(k, MOUSE_LEFT))
		{
			v = new_vertex(e->mouse->x, e->mouse->y);
			if (l->s_tmp)
			{
				if (shape_has_vertex(l->s_tmp, v))
					ft_putstr("end_shape\n");
				else
					shape_add(l->s_tmp, v);
			}
			else
			{
				if (!(l->v_tmp = layer_has_vertex(l, v)))
					l->s_tmp = new_shape(v);
				else
					ft_putstr("vertex_move\n");
			}
			ft_putstr("mouseLeft Rising\n");
		}
		else if (key_is_falling(k, MOUSE_LEFT))
		{
			if (l->v_tmp)
			{
				v = new_vertex(e->mouse->x, e->mouse->y);
				l->v_tmp = 0;
			}
			ft_putstr("mouseLeft Falling\n");
		}
	}
	return ;
}

static void			event_layer_manage(t_engine *e)
{
	t_keyboard		*k;
	t_image			*img;

	k = e->keyboard;
	if (key_is_pressed(k, KEY_CTRL_LEFT))
	{
		//add_layer
		if (key_is_rising(k, KEY_PAD_ADD))
		{
			if ((img = new_image(e->mlx->id, e->mlx->win->id, WIDTH, HEIGH)))
				gui_add_layer(e->gui, new_layer(img, 1));
		}
		//del_layer
		else if (key_is_rising(k, KEY_PAD_SUB))
			gui_remove_layer(e->gui);
	}
	if (key_is_rising(k, KEY_DEL))
		if (e->)
	return ;
}

void				event_refresh(t_engine *e)
{
	if (key_is_pressed(e->keyboard, KEY_ESCAPE))
		engine_destroy(e);
	event_layer_iter(e);
	event_layer_draw(e);
	event_layer_manage(e);
	return ;
}