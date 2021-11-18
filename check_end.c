/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:26:19 by rcheiko           #+#    #+#             */
/*   Updated: 2021/10/01 15:39:27 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_collec(t_struct *d)
{
	if (d->map[d->y_p / d->size_cub][d->x_p / d->size_cub] == 'C')
	{
		d->map[d->y_p / d->size_cub][d->x_p / d->size_cub] = '0';
		d->obj--;
	}
}

void	is_end(t_struct *d)
{
	if (d->map[d->y_p / d->size_cub][d->x_p / d->size_cub] == 'E')
	{
		if (d->obj == 0)
		{
			printf("%d\n", ++d->cpt_move);
			exit(0);
		}
	}
}
