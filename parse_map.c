/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:41:02 by rcheiko           #+#    #+#             */
/*   Updated: 2021/09/30 16:11:36 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gnl_mal_map(t_struct *d)
{
	char	*str;

	str = NULL;
	d->ret = 1;
	while (d->ret > 0)
	{
		d->ret = get_next_line(d->fd, &str);
		d->mal_map++;
		free_str(str);
	}
	fill_map(d);
}

void	fill_map(t_struct *d)
{
	d->i = 0;
	d->str = NULL;
	close(d->fd);
	d->fd = open(d->path_map, O_RDONLY);
	d->map = malloc(sizeof(char *) * d->mal_map - 1);
	d->ret = 1;
	while (d->ret > 0)
	{
		d->ret = get_next_line(d->fd, &d->str);
		if (d->i != d->mal_map - 1)
		{
			d->map[d->i] = ft_strdup(d->str);
			d->map[d->i][ft_strlen(d->str)] = '\0';
			free_str(d->str);
		}
		d->i++;
	}
}
