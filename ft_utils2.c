/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:17:49 by rcheiko           #+#    #+#             */
/*   Updated: 2021/10/01 14:25:17 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_struct *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	check_charset(char c, char *check)
{
	int	i;

	i = 0;
	while (check[i])
	{
		if (check[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	calc_collectible(t_struct *d)
{
	int	i;
	int	j;

	i = 0;
	d->obj = 0;
	while (d->mal_map - 1 != i && d->map && d->map[i])
	{
		j = 0;
		while (d->map[i] && d->map[i][j])
		{
			if (d->map[i][j] == 'C')
				d->obj++;
			j++;
		}
		i++;
	}
}
