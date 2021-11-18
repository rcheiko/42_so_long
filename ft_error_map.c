/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:32:47 by rcheiko           #+#    #+#             */
/*   Updated: 2021/09/30 17:25:03 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_error_map(t_struct *d)
{
	d->i = 0;
	d->j = ft_strlen(d->map[0]);
	while (d->map[d->i] && d->mal_map - 1 != d->i)
	{
		if (ft_strlen(d->map[d->i]) != d->j)
		{
			printf("Error, map must be rectangular\n");
			exit(0);
		}
		d->i++;
	}
}

void	check_error_map2(t_struct *d)
{
	d->i = 0;
	while (d->map[0][d->i])
	{
		if (d->map[0][d->i] != '1')
		{
			printf("Map must be closed by wall\n");
			exit(0);
		}
		d->i++;
	}
	d->i = 0;
	while (d->map[d->mal_map - 2][d->i])
	{
		if (d->map[d->mal_map - 2][d->i] != '1')
		{
			printf("Map must be closed by wall\n");
			exit(0);
		}
		d->i++;
	}
}

void	check_error_map3(t_struct *d)
{
	d->i = 0;
	while (d->mal_map - 1 != d->i && d->map[d->i] && d->map[d->i][0])
	{
		if (d->map[d->i][0] != '1')
		{
			printf("Map must be closed by wall\n");
			exit(0);
		}
		d->i++;
	}
	d->i = 0;
	while (d->mal_map - 1 != d->i && d->map[d->i] && d->mal_map - 1 != d->i)
	{
		if (d->map[d->i][ft_strlen(d->map[d->i]) - 1] != '1')
		{
			printf("Map must be closed by wall\n");
			exit(0);
		}
		d->i++;
	}
}

void	call_check_map(t_struct *d)
{
	check_error_map(d);
	check_error_map2(d);
	check_error_map3(d);
	check_starting_pos(d);
	check_exit_pos(d);
	check_collectible_pos(d);
	check_five_char(d);
}
