/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/22 17:52:25 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/23 23:42:42 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void			event_catch_mouse(t_keyboard *k)
{
	if (key_is_pressed(k, MOUSE_SCROLL_UP))
	{
		k->reg_key &= k->reg_key ^ (1 << k->reg_id[MOUSE_SCROLL_UP]);
		ft_putstr("mouseScrollUp\n");
	}
	else if (key_is_pressed(k, MOUSE_SCROLL_DOWN))
	{
		k->reg_key &= k->reg_key ^ (1 << k->reg_id[MOUSE_SCROLL_DOWN]);
		ft_putstr("mouseScrollDown\n");
	}
	if (key_is_pressed(k, MOUSE_RIGHT))
		ft_putstr("mouseRight\n");
	else if (key_is_pressed(k, MOUSE_LEFT))
		ft_putstr("mouseLeft\n");
	if (key_is_pressed(k, MOUSE_MID))
		ft_putstr("mouseMiddle\n");
	return ;
}

static void			event_catch_keyboard(t_keyboard *k)
{
	if (key_is_pressed(k, KEY_SPACE))
		ft_putstr("Space\n");
	return ;
}

void				event_refresh(t_engine *e)
{
	event_catch_mouse(e->keyboard);
	event_catch_keyboard(e->keyboard);
	if (key_is_pressed(e->keyboard, KEY_ESCAPE))
		engine_destroy(e);
	return ;
}