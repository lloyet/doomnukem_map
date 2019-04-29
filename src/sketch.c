/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sketch.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/27 18:14:50 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/29 23:52:14 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

t_sketch			*new_sketch(void *mlx_id)
{
	t_sketch		*sketch;
	t_grid			*grid;

	if (!(sketch = (t_sketch*)ft_memalloc(sizeof(t_sketch))))
		return (0);
	if (!(grid = new_grid(new_image(mlx_id, WIDTH, HEIGH))))
		return (sketch);
	sketch->board = new_tree((void*)grid, sizeof(grid), E_CYCLE);
	sketch->marker = &sketch->board;
	sketch->size = 1;
	return (sketch);
}

void				sketch_destroy(t_sketch *sketch)
{
	cycle_delall(&sketch->board);
	*sketch->marker = 0;
	ft_memdel((void**)&sketch);
	return ;
}

t_node				*new_layer(t_grid *grid)
{
	t_node			*layer;

	if (!(layer = new_node((void *)grid, sizeof(grid))))
		return (0);
	grid_destroy(grid);
	return (layer);
}