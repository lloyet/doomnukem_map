/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   engine.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 20:07:01 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 04:46:09 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void				device_register_keys(t_keyboard *k)
{
	register_new_key(k, KEY_ESCAPE);
	register_new_key(k, KEY_SPACE);
	register_new_key(k, KEY_DEL);
	register_new_key(k, KEY_CTRL_LEFT);
	register_new_key(k, MOUSE_LEFT);
	register_new_key(k, MOUSE_RIGHT);
	register_new_key(k, MOUSE_MID);
	register_new_key(k, MOUSE_SCROLL_DOWN);
	register_new_key(k, MOUSE_SCROLL_UP);
}

void					engine_destroy(t_engine *e)
{
	framework_destroy(e->mlx);
	keyboard_destroy(e->keyboard);
	mouse_destroy(e->mouse);
	ft_memdel((void **)&e);
	exit(1);
}

t_engine				*new_engine(void)
{
	t_engine			*e;
	t_image				*bg;

	if (!(e = (t_engine *)ft_memalloc(sizeof(t_engine))))
		return (0);
	if (!(e->mlx = new_framework()))
		return (0);
	if (!(e->keyboard = new_keyboard(KEYBOARD_S)))
		return (0);
	if (!(e->mouse = new_mouse(e->keyboard)))
		return (0);
	if (!(bg = new_image(e->mlx->id, WIDTH, HEIGH)))
		return (0);
	if (!(e->loader = new_loader(new_layer(bg))))
		return (0);
	image_attach(bg, e->mlx->win);
	image_fill(bg, CLR_BG);
	device_register_keys(e->keyboard);
	return (e);
}
