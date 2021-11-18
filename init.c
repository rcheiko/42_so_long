/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:50:10 by rcheiko           #+#    #+#             */
/*   Updated: 2021/10/01 15:40:47 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_struct *d, char **av)
{
	d->size_cub = 45;
	d->cpt_move = 0;
	d->mal_map = 0;
	d->fd = open(av[1], O_DIRECTORY);
	if (d->fd != -1)
	{
		printf("Error Path is a directory\n");
		exit(0);
	}
	d->fd = open(av[1], O_RDONLY);
	if (d->fd == -1)
	{
		printf("Error Path\n");
		exit(0);
	}
	d->path_map = av[1];
	d->map = NULL;
}
