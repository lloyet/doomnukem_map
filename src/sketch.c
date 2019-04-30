/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sketch.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/27 18:14:50 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/30 21:51:04 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

t_payload			*new_sketch()
{
	return (new_payload())
}
}

void				sketch_destroy(t_sketch *sketch)
{
	tree_destroy(&sketch->board, layer_destroy);
	*sketch->marker = 0;
	ft_memdel((void**)&sketch);
	return ;
}

t_node				*new_layer(t_grid *grid)
{
	t_node			*layer;

	if (!(layer = new_node((void *)grid)))
		return (0);
	grid_destroy(grid);
	return (layer);
}

void				layer_destroy(void *grid)
{
	t_grid			*grid_;

	grid_ = (t_grid*)grid;
	grid_destroy(grid_);
	return (0);
}