/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/22 17:52:25 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/05 06:18:15 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/doom_map.h"

static void			event_layer_iter(t_engine *e)
{
	t_keyboard 		*k;

	k = e->keyboard;
	if (key_is_pressed(k, MOUSE_SCROLL_UP))
	{
		k->reg_key &= k->reg_key ^ (1 << k->reg_id[MOUSE_SCROLL_UP]);
		if (key_is_pressed(k, KEY_CTRL_LEFT))
			gui_next(e->gui);
		else
			ft_putstr("Zoom In\n");
	}
	else if (key_is_pressed(k, MOUSE_SCROLL_DOWN))
	{
		k->reg_key &= k->reg_key ^ (1 << k->reg_id[MOUSE_SCROLL_DOWN]);
		if (key_is_pressed(k, KEY_CTRL_LEFT))
			gui_prev(e->gui);
		else
			ft_putstr("Zoom Out\n");
	}
	return ;
}

static void			event_layer_draw(t_engine *e)
{
	t_keyboard		*k;

	k = e->keyboard;
	if (key_is_pressed(k, MOUSE_RIGHT))
		ft_putstr("mouseRight\n");
	else if (key_is_pressed(k, MOUSE_LEFT))
		ft_putstr("mouseLeft\n");
	if (key_is_pressed(k, MOUSE_MID))
		ft_putstr("mouseMiddle\n");
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
		if (key_is_pressed(k, KEY_PAD_ADD))
		{
			if ((img = new_image(e->mlx->id, e->mlx->win->id, WIDTH, HEIGH)))
				gui_add_layer(e->gui, new_layer(img));
		}
		//del_layer
		else if (key_is_pressed(k, KEY_PAD_SUB))
			gui_remove_layer(e->gui);
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