/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   misc.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 21:12:24 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/26 04:45:03 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

void				debug_display(t_engine *e)
{
	if (!e->mlx->win->menu)
	{
		mlx_string_put(e->mlx->id, e->mlx->win->id, 0, 0, 0x00D33682, "Mouse");
		mlx_string_put(e->mlx->id, e->mlx->win->id, 0, 20, 0x00D33682, ft_strjoin("X: ", ft_itoa(e->mouse->x)));
		mlx_string_put(e->mlx->id, e->mlx->win->id, 100, 20, 0x00D33682, ft_strjoin("Y: ", ft_itoa(e->mouse->y)));
	}
	return ;
}
