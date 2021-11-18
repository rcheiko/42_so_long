/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:08:41 by rcheiko           #+#    #+#             */
/*   Updated: 2021/10/01 15:01:44 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress(int keycode, t_struct *d)
{
	if (keycode == 13)
	{
		movement_w(d);
	}
	if (keycode == 0)
	{
		movement_a(d);
	}
	if (keycode == 1)
	{
		movement_s(d);
	}
	if (keycode == 2)
	{
		movement_d(d);
	}
	if (keycode == 53)
	{
		movement_fl_esc();
	}
	return (0);
}

int	key_exit(t_struct *d)
{
	(void) d;
	exit (0);
}
