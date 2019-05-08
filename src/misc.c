/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   misc.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 21:12:24 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/08 23:20:49 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/doom_map.h"

static void			debug_shape(t_engine *e, t_layer *l)
{
	mlx_string_put(e->mlx->id, e->mlx->win->id,
		25, 350, CLR_STR, "-~- [SECTOR] -~-");
	mlx_string_put(e->mlx->id, e->mlx->win->id,
		30, 375, CLR_STR, "  Floor : ");
	mlx_string_put(e->mlx->id, e->mlx->win->id,
		130, 375, CLR_VAR, ft_itoa(l->s_tmp->floor));
	mlx_string_put(e->mlx->id, e->mlx->win->id,
		30, 400, CLR_STR, "  Ceil  : ");
	mlx_string_put(e->mlx->id, e->mlx->win->id,
		130, 400, CLR_VAR, ft_itoa(l->s_tmp->ceil));
	return ;
}

static void			debug_layer(t_engine *e)
{
	t_layer			*l;
	char			*str;

	str = ft_itoa(e->gui->layer->index);
	l = (t_layer*)e->gui->iterator->content;
	mlx_string_put(e->mlx->id, e->mlx->win->id, 25, 50,
		CLR_STR, "-~- [CURSOR] -~-");
	mlx_string_put(e->mlx->id, e->mlx->win->id, 40, 75, CLR_STR, "X: ");
	mlx_string_put(e->mlx->id, e->mlx->win->id, 65, 75, CLR_VAR, e->mouse->x
		- O_SKETCH > -1 ? ft_itoa(e->mouse->x - O_SKETCH) : "0");
	mlx_string_put(e->mlx->id, e->mlx->win->id, 115, 75, CLR_STR, "Y: ");
	mlx_string_put(e->mlx->id, e->mlx->win->id, 140, 75, CLR_VAR, (e->mouse->y
		> -1) ? ft_itoa(e->mouse->y) : "0");
	mlx_string_put(e->mlx->id, e->mlx->win->id, 25,
		HEIGH - 50, CLR_STR, "Layer: ");
	mlx_string_put(e->mlx->id, e->mlx->win->id, 100,
		HEIGH - 50, CLR_VAR, str[0] != '0' ? str : "0");
	mlx_string_put(e->mlx->id, e->mlx->win->id, 25, 200,
		CLR_STR, "-~- [MODE] -~-");
	mlx_string_put(e->mlx->id, e->mlx->win->id, 25, 225, CLR_VAR,
		l->mode == L_EDIT ? "     EDIT" : "    VISUAL");
	if (l->s_tmp && l->mode == L_EDIT)
		debug_shape(e, l);
	return ;
}

static void			debug_entity(t_engine *e)
{
	mlx_string_put(e->mlx->id, e->mlx->win->id, 25, 275,
		CLR_STR, "-~- [PIPET] -~-");
	mlx_string_put(e->mlx->id, e->mlx->win->id, 25, 300, CLR_VAR,
		e->gui->pipet != P_ENTITY ? "     SPAWN" : "    ENTITY");
	return ;
}

static void			debug_menu(t_engine *e)
{
	(void)e;
	return ;
}

void				debug_display(t_engine *e)
{
	if (!e->mlx->win->menu)
	{
		mlx_string_put(e->mlx->id, e->mlx->win->id, WIDTH - 75, 0,
			0x0000FF22, "FPS: ");
		mlx_string_put(e->mlx->id, e->mlx->win->id, WIDTH - 25, 0,
			0x0000FF22, ft_itoa(1.0 / e->mlx->frame));
		if (e->gui->iterator != e->gui->layer->begin)
		{
			debug_layer(e);
			debug_entity(e);
		}
		else
			debug_menu(e);
	}
	return ;
}
