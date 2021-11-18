/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:39:17 by rcheiko           #+#    #+#             */
/*   Updated: 2021/10/01 15:39:04 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	aff_carre(t_struct *d, int color, int x, int y)
{
	d->i = 0;
	while (d->i < d->size_cub)
	{
		d->j = 0;
		while (d->j < d->size_cub)
		{
			my_mlx_pixel_put(d, x + d->i, y + d->j, color);
			d->j++;
		}
		d->i++;
	}
}

void	aff_map(t_struct *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->mal_map - 1 != i && d->map && d->map[i])
	{
		j = 0;
		while (d->map[i] && d->map[i][j])
		{
			if (d->map[i][j] == '1')
				aff_carre(d, 0xFFFFFF, j * d->size_cub, i * d->size_cub);
			if (d->map[i][j] == 'E')
				aff_carre(d, 0xA78686, j * d->size_cub, i * d->size_cub);
			if (d->map[i][j] == 'C')
				aff_carre(d, 0x83AAFF, j * d->size_cub, i * d->size_cub);
			j++;
		}
		i++;
	}
}

int	s_cub(t_struct *d, int i)
{
	int	k;

	k = i * d->size_cub;
	return (k);
}
