/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:02:19 by rcheiko           #+#    #+#             */
/*   Updated: 2021/10/01 15:40:50 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>

# define BUFFER_SIZE 500

typedef struct s_struct
{
	int		obj;
	int		x_p;
	int		y_p;
	int		size_cub;
	int		cpt_move;
	int		largeur;
	int		longueur;
	int		i;
	int		j;
	int		total;
	int		ret;
	int		fd;
	int		mal_map;
	char	*str;
	char	*path_map;
	char	**map;
	void	*mlx;
	void	*window;
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
}				t_struct;

void	init(t_struct *d, char **av);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *str);
int		ft_strcmp(char *s1, char *s2);
void	gnl_mal_map(t_struct *d);
void	fill_map(t_struct *d);

//aff_map.c
void	aff_carre(t_struct *d, int color, int x, int y);
void	aff_map(t_struct *d);

//ft_error_map.c
void	check_error_map(t_struct *d);
void	check_error_map2(t_struct *d);
void	check_error_map3(t_struct *d);
void	call_check_map(t_struct *d);

//ft_char_map.c
void	check_starting_pos(t_struct *d);
void	check_exit_pos(t_struct *d);
void	check_collectible_pos(t_struct *d);
void	check_five_char(t_struct *d);
void	start_pos_p(t_struct *d);

//ft_utils2.c
void	my_mlx_pixel_put(t_struct *d, int x, int y, int color);
int		check_charset(char c, char *check);
void	calc_collectible(t_struct *d);

//check_end.c
void	is_collec(t_struct *d);
void	is_end(t_struct *d);

//so_long.c
void	error(int ac, char **av);
int		aff_all(t_struct *d);

//keyhook
int		keypress(int keycode, t_struct *d);
int		key_exit(t_struct *d);

//movement
void	movement_w(t_struct *d);
void	movement_s(t_struct *d);
void	movement_d(t_struct *d);
void	movement_a(t_struct *d);
void	movement_fl_esc(void);

//get_next_line
char	*ft_strdup(char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dest, char *src);
int		is_newline(char *str, char c);
char	*creat_line(char *str, char *buffer);
int		get_rest(char **line, char *str);
int		get_next_line(int fd, char **line);
void	free_str(char *str);
void	free_str2(char **str);

#endif
