/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:15:11 by rcheiko           #+#    #+#             */
/*   Updated: 2021/10/01 15:01:09 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement_w(t_struct *d)
{
	d->y_p -= d->size_cub;
	is_collec(d);
	is_end(d);
	d->cpt_move++;
	if (d->map[d->y_p / d->size_cub][(d->x_p / d->size_cub)] == '1')
	{
		d->cpt_move--;
		d->y_p += d->size_cub;
	}
	else
		printf("%d\n", d->cpt_move);
}

void	movement_s(t_struct *d)
{
	d->y_p += d->size_cub;
	is_collec(d);
	is_end(d);
	d->cpt_move++;
	if (d->map[d->y_p / d->size_cub][d->x_p / d->size_cub] == '1')
	{
		d->cpt_move--;
		d->y_p -= d->size_cub;
	}
	else
		printf("%d\n", d->cpt_move);
}	

void	movement_d(t_struct *d)
{
	d->x_p += d->size_cub;
	is_collec(d);
	is_end(d);
	d->cpt_move++;
	if (d->map[d->y_p / d->size_cub][d->x_p / d->size_cub] == '1')
	{
		d->cpt_move--;
		d->x_p -= d->size_cub;
	}
	else
		printf("%d\n", d->cpt_move);
}

void	movement_a(t_struct *d)
{
	d->x_p -= d->size_cub;
	is_collec(d);
	is_end(d);
	d->cpt_move++;
	if (d->map[d->y_p / d->size_cub][d->x_p / d->size_cub] == '1')
	{
		d->cpt_move--;
		d->x_p += d->size_cub;
	}
	else
		printf("%d\n", d->cpt_move);
}

void	movement_fl_esc(void)
{
	exit(0);
}
