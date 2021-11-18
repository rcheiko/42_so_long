/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:02:06 by rcheiko           #+#    #+#             */
/*   Updated: 2021/10/01 15:12:03 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int ac, char **av)
{
	char	*str;

	if (ac > 2 || ac == 1 || ft_strlen(av[1]) == 4)
	{
		printf("ERROR Argument\n");
		exit(0);
	}
	if (ac == 2)
	{
		str = ft_substr(av[1], ft_strlen(av[1]) - 4, 4);
		if (ft_strcmp(str, ".ber") != 0)
		{
			free_str(str);
			printf("ERROR .ber\n");
			exit(0);
		}
		free_str(str);
	}
}

int	aff_all(t_struct *d)
{
	aff_map(d);
	aff_carre(d, 0xDCACFF, d->x_p, d->y_p);
	mlx_put_image_to_window(d->mlx, d->window, d->img, 0, 0);
	mlx_destroy_image(d->mlx, d->img);
	d->img = mlx_new_image(d->mlx, d->longueur, d->largeur);
	d->addr = mlx_get_data_addr(d->img,
			&d->bits_per_pixel, &d->line_length, &d->endian);
	return (0);
}

int	main(int ac, char **av)
{
	t_struct	d;

	error(ac, av);
	init(&d, av);
	gnl_mal_map(&d);
	call_check_map(&d);
	start_pos_p(&d);
	calc_collectible(&d);
	d.longueur = ft_strlen(d.map[0]) * d.size_cub;
	d.largeur = (d.mal_map - 1) * d.size_cub;
	d.mlx = mlx_init();
	d.window = mlx_new_window(d.mlx, d.longueur, d.largeur, "SO_LONG");
	d.img = mlx_new_image(d.mlx, d.longueur, d.largeur);
	d.addr = mlx_get_data_addr(d.img,
			&d.bits_per_pixel, &d.line_length, &d.endian);
	mlx_hook(d.window, 2, 0, keypress, &d);
	mlx_hook(d.window, 17, 0, key_exit, &d);
	mlx_loop_hook(d.mlx, aff_all, &d);
	mlx_loop(d.mlx);
	return (0);
}
