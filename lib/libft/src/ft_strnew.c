/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 14:02:15 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/19 00:32:18 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (i < size + 1)
		str[i++] = 0;
	return (str);
}
