/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/22 17:52:25 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 18:33:53 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void			event_catch_mouse(t_engine *e)
{
	t_keyboard 		*k;

	k = e->keyboard;
	if (key_is_pressed(k, MOUSE_SCROLL_UP))
	{
		k->reg_key &= k->reg_key ^ (1 << k->reg_id[MOUSE_SCROLL_UP]);
		if (key_is_pressed(k, KEY_CTRL_LEFT))
			loader_next(e->loader);
		else
			ft_putstr("Zoom In\n");
	}
	else if (key_is_pressed(k, MOUSE_SCROLL_DOWN))
	{
		k->reg_key &= k->reg_key ^ (1 << k->reg_id[MOUSE_SCROLL_DOWN]);
		if (key_is_pressed(k, KEY_CTRL_LEFT))
			loader_prev(e->loader);
		else
			ft_putstr("Zoom Out\n");
	}
	if (key_is_pressed(k, MOUSE_RIGHT))
		ft_putstr("mouseRight\n");
	else if (key_is_pressed(k, MOUSE_LEFT))
		ft_putstr("mouseLeft\n");
	if (key_is_pressed(k, MOUSE_MID))
		ft_putstr("mouseMiddle\n");
	return ;
}

static void			event_catch_keyboard(t_engine *e)
{
	t_keyboard		*k;

	k = e->keyboard;
	if (key_is_pressed(k, KEY_SPACE))
		ft_putstr("Space\n");
	if (key_is_pressed(k, KEY_CTRL_LEFT))
	{
		if (key_is_pressed(k, KEY_PAD_ADD))
			loader_add(e->loader, new_layer(new_image(e->mlx->id, e->mlx->win->id, WIDTH, HEIGH)));
			//add_layer
		else if (key_is_pressed(k, KEY_PAD_SUB))
			loader_remove(e->loader);
			//del_layer
	}
	return ;
}

void				event_refresh(t_engine *e)
{
	if (key_is_pressed(e->keyboard, KEY_ESCAPE))
		engine_destroy(e);
	event_catch_mouse(e);
	event_catch_keyboard(e);
	return ;
}