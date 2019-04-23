/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/15 01:06:33 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/23 23:48:08 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

static int				refresh_stack(t_engine *e)
{
	//image_fill(e->mlx->win->bg, 0xFFFFFF00);
	image_pixel_put(e->mlx->win->bg, 10, 10, 0xFFFFFFFF);
	mlx_put_image_to_window(e->mlx->id, e->mlx->win->id, e->mlx->win->bg->id, 0, 0);
	debug_display(e);
	image_clear(e->mlx->win->bg);
	event_refresh(e);
	return (0);
}

static void				init_hook(t_engine *e)
{
	mlx_hook(e->mlx->win->id,
			MOTIONNOTIFY, POINTERMOTIONMASK, mouse_motion_hook, e->mouse);
	mlx_hook(e->mlx->win->id,
			KEYPRESS, KEYPRESSMASK, key_press_hook, e->keyboard);
	mlx_hook(e->mlx->win->id,
			BUTTONPRESS, BUTTONPRESSMASK, mouse_press_hook, e->mouse);
	mlx_hook(e->mlx->win->id,
			KEYRELEASE, KEYRELEASEMASK, key_release_hook, e->keyboard);
	mlx_hook(e->mlx->win->id,
			BUTTONRELEASE, BUTTONRELEASEMASK, mouse_release_hook, e->mouse);
	mlx_hook(e->mlx->win->id,
			DESTROYNOTIFY, STRUCTURENOTIFYMASK, destroy_window_hook, e);
	mlx_loop_hook(e->mlx->id, refresh_stack, e);
	mlx_loop(e->mlx->id);
	return ;
}

int						main(void)
{
	t_engine			*e;

	if (!(e = new_engine()))
		return (0);
	init_hook(e);
	return (0);
}
