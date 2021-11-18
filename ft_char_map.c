/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:59:18 by rcheiko           #+#    #+#             */
/*   Updated: 2021/09/30 22:35:17 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_starting_pos(t_struct *d)
{
	d->total = 0;
	d->i = 0;
	while (d->mal_map - 1 != d->i && d->map && d->map[d->i])
	{
		d->j = 0;
		while (d->map[d->i] && d->map[d->i][d->j])
		{
			if (d->map[d->i][d->j] == 'P' && d->total > 0)
			{
				printf("Error need just one starting position\n");
				exit(0);
			}
			if (d->map[d->i][d->j] == 'P')
				d->total++;
			d->j++;
		}
		d->i++;
	}
	if (d->total == 0)
	{
		printf("Error need one starting position\n");
		exit(0);
	}
}

void	check_exit_pos(t_struct *d)
{
	d->total = 0;
	d->i = 0;
	while (d->mal_map - 1 != d->i && d->map && d->map[d->i])
	{
		d->j = 0;
		while (d->map[d->i] && d->map[d->i][d->j])
		{
			if (d->map[d->i][d->j] == 'E')
				d->total++;
			d->j++;
		}
		d->i++;
	}
	if (d->total == 0)
	{
		printf("Error need one minimum exit position\n");
		exit(0);
	}
}

void	check_collectible_pos(t_struct *d)
{
	d->total = 0;
	d->i = 0;
	while (d->mal_map - 1 != d->i && d->map && d->map[d->i])
	{
		d->j = 0;
		while (d->map[d->i] && d->map[d->i][d->j])
		{
			if (d->map[d->i][d->j] == 'C')
				d->total++;
			d->j++;
		}
		d->i++;
	}
	if (d->total == 0)
	{
		printf("Error need one minimum collectible position\n");
		exit(0);
	}
}

void	check_five_char(t_struct *d)
{
	d->i = 0;
	while (d->mal_map - 1 != d->i && d->map && d->map[d->i])
	{
		d->j = 0;
		while (d->map[d->i] && d->map[d->i][d->j])
		{
			if (check_charset(d->map[d->i][d->j], "01CEP") == 0)
			{
				printf("Error Character no valid\n");
				exit(0);
			}
			d->j++;
		}
		d->i++;
	}
}

void	start_pos_p(t_struct *d)
{
	d->i = 0;
	while (d->mal_map - 1 != d->i && d->map && d->map[d->i])
	{
		d->j = 0;
		while (d->map[d->i] && d->map[d->i][d->j])
		{
			if (d->map[d->i][d->j] == 'P')
			{
				d->x_p = d->j * d->size_cub;
				d->y_p = d->i * d->size_cub;
			}
			d->j++;
		}
		d->i++;
	}
}
