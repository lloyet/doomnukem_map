/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   loader_it.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 02:50:28 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 04:41:00 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

void					loader_next(t_payload *loader)
{
	if ((*loader->iterator)->child)
	{
		((t_layer*)((*loader->iterator)->content))->color = CLR_SHADOW;
		loader->iterator = &(*loader->iterator)->child;
		((t_layer*)((*loader->iterator)->content))->color = CLR_LAYER;
	}
	return ;
}

void					loader_prev(t_payload *loader)
{
	if ((*loader->iterator)->parent)
	{
		((t_layer*)((*loader->iterator)->content))->color = CLR_SHADOW;
		loader->iterator = &(*loader->iterator)->parent;
		((t_layer*)((*loader->iterator)->content))->color = CLR_LAYER;
	}
	return ;
}