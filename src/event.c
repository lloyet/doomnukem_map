/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/22 17:52:25 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/07 23:46:47 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/doom_map.h"

static void			event_shape(t_keyboard *k, t_layer *l)
{
	if (key_is_pressed(k, KEY_C))
	{
		if (key_is_rising(k, KEY_PAD_ADD) && l->s_tmp && !l->mode)
			l->s_tmp->ceil++;
		else if (key_is_rising(k, KEY_PAD_SUB) && l->s_tmp
			&& !l->mode && (l->s_tmp->ceil - 1 > - 1))
			l->s_tmp->ceil--;
	}
	else if (key_is_pressed(k, KEY_F))
	{
		if (key_is_rising(k, KEY_PAD_ADD) && l->s_tmp && !l->mode)
			l->s_tmp->floor++;
		else if (key_is_rising(k, KEY_PAD_SUB) && l->s_tmp && !l->mode
			&& (l->s_tmp->floor - 1 > -1))
			l->s_tmp->floor--;
	}
	return ;
}

static void			event_layer_draw(t_engine *e)
{
	t_layer			*l;
	t_keyboard		*k;

	l = (t_layer*)e->gui->iterator->content;
	if (l->is_draw && e->mouse->y > -1 && e->mouse->x > 250)
	{
		k = e->keyboard;
		if (key_is_pressed(k, MOUSE_RIGHT))
			ft_putstr("mouseRight\n");
		if (key_is_rising(k, MOUSE_LEFT))
			event_draw_tmp(l, e->mouse->x, e->mouse->y);
		else if (key_is_falling(k, MOUSE_LEFT) && l->v_tmp)
		{
			vertex_update(l->v_tmp, e->mouse->x, e->mouse->y);
			l->v_tmp = 0;
			ft_putstr("mouseLeft Falling\n");
		}
		if (key_is_pressed(k, MOUSE_LEFT) && l->v_tmp)
			vertex_update(l->v_tmp, e->mouse->x, e->mouse->y);
		event_shape(k, l);
	}
	return ;
}

static void			event_layer_iter(t_engine *e)
{
	t_keyboard 		*k;

	k = e->keyboard;
	if (key_is_rising(k, MOUSE_SCROLL_UP))
		gui_next(e->gui);
	else if (key_is_rising(k, MOUSE_SCROLL_DOWN))
		gui_prev(e->gui);
	return ;
}

static void			event_layer_manage(t_engine *e)
{
	t_layer			*l;
	t_keyboard		*k;
	t_image			*img;

	k = e->keyboard;
	if (key_is_pressed(k, KEY_CTRL_LEFT))
	{
		l = (t_layer*)e->gui->iterator->content;
		if (key_is_rising(k, KEY_PAD_ADD))
		{
			if ((img = new_image(e->mlx->id, e->mlx->win->id, WIDTH, HEIGH)))
				gui_add_layer(e->gui, new_layer(img, 1));
		}
		else if (key_is_rising(k, KEY_PAD_SUB))
			gui_remove_layer(e->gui);
	}
	if (key_is_rising(k, KEY_DEL) && l->is_draw)
	{
		if (l->s_tmp && !l->mode)
		{
			shape_destroy(l->s_tmp);
			l->s_tmp = 0;
			l->mode = 1;
		}
		else if (l->s_tmp)
			event_delete_tmp((t_layer*)e->gui->iterator->content);
	}
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
