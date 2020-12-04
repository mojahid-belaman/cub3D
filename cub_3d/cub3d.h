/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <mbelaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:12:01 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/23 12:23:33 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# define BUFFER_SIZE 10
# define END_GAME 0
# define NO_ARG 			-1
# define FILE_ERROR 		-3
# define EXTENSION_ERROR 	3
# define MAP_ERROR 4
# define GNL_ERROR  5
# define EXEC_ERROR 6
# define MAP_ELM_REP 7
# define EXEC_ERR 8
# define RSL_ERR 9
# define TEX_ERR 10
# define COLOR_ERR 11
# define ESP_ERR 12
# define CHIFRE_COLOR 15
# define MIN_MAX_COLOR 14
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_R_L 123
# define KEY_R_R 124
# define EXIT_KEY 53
# define LINE_NOTEXIST 20
# define BMP_FILE_ERR 21
# define NUM_SP 4096
# define ARG_ERR 30

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_point
{
	int			x_sp;
	int			y_sp;
}					t_point;

typedef struct		s_map
{
	int				x;
	int				y;
	t_point			pos[NUM_SP];
	int				sp_count;
	int				step;
	long	long	resol_w;
	long	long	resol_h;
	char			orient;
	double			pos_x;
	double			pos_y;
	char			dir_count;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*sprite;
	char			*tmp_map;
	char			**map;
	t_rgb			floor;
	t_rgb			ceilling;
}					t_map;

typedef struct		s_sprite
{
	double			*z_buffer;
	int				spr_w;
	int				spr_h;
	int				spr_s_l;
	int				spr_end;
	int				spr_bbp;
	int				*spr_data;
	void			*spr_img;
	int				sp_ord[NUM_SP];
	double			sp_dst[NUM_SP];
	double			sp_x;
	double			sp_y;
	double			inv_det;
	double			tsf_x;
	double			tsf_y;
	int				sp_scrn_x;
	int				sp_h;
	int				dr_st_y;
	int				dr_en_y;
	int				sp_wdth;
	int				dr_st_x;
	int				dr_en_x;
	int				tex_x;
	int				d;
	int				tex_y;
	int				color;
}					t_sprite;

typedef struct		s_bmp
{
	int				save;
	int				width;
	int				height;
	int				bit_count;
	int				width_in_bytes;
	int				img_size;
	int				bi_size;
	int				bmf_offbits;
	int				filesize;
	int				bit_planes;
	unsigned char	*header;
	unsigned char	*buf;
	int				row;
	int				col;
	long			color;
	int				r;
	int				g;
	int				b;
}					t_bmp;

typedef struct		s_var
{
	int				up;
	int				down;
	int				right;
	int				left;
	int				rt_r;
	int				rt_l;
	void			*mlx_ptr;
	void			*win_ptr;
	int				tw;
	int				th;
	void			*xfi_no;
	void			*xfi_so;
	void			*xfi_we;
	void			*xfi_ea;
	int				*texture;
	double			p_x;
	double			p_y;
	double			d_x;
	double			d_y;
	double			pl_x;
	double			pl_y;
	double			cmr_x;
	int				x;
	double			rd_x;
	double			rd_y;
	int				map_x;
	int				map_y;
	double			sd_x;
	double			sd_y;
	double			dd_x;
	double			dd_y;
	double			p_w_d;
	int				stp_x;
	int				stp_y;
	int				hit;
	int				side;
	int				color;
	double			o_d_x;
	double			o_p_x;
	void			*img;
	int				*data;
	int				*data_no;
	int				*data_so;
	int				*data_we;
	int				*data_ea;
	int				bpp;
	int				sl;
	int				endian;
	int				l_h;
	int				ds;
	int				de;
	int				tex_w;
	int				tex_h;
	double			wal_x;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
	int				y;
	int				save;
	t_map			map;
	t_sprite		sprit;
}					t_var;

void				specifie_side(t_var *var);
void				draw_texture(t_var *var);
void				direction_ray(t_var *var);
void				move_up(t_var *var);
void				move_down(t_var *var);
void				move_right(t_var *var);
void				move_left(t_var *var);
void				rotation_left(t_var *var);
void				rotation_right(t_var *var);
void				wall_line_height(t_var *var);
void				wall_is_hit(t_var *var);
void				draw_line_floor_ceilling(t_var *var);
void				sprite(t_var *var);
void				get_resolution(char *line, t_var *var);
void				hundle_error(int err, t_var *var);
char				**free_table(char **tab, int size);
int					check_len_tab(char **tab);
int					check_two_str(char *rsl, char *src);
void				get_texutre(char *line, t_var *var);
void				get_color(char *line, t_var *var);
int					len_1d(char *s);
int					check_width_line(t_map *map, char *line, int x);
void				init_map(t_var *var);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *src);
size_t				ft_strlen(const char *str);
int					get_next_line(int fd, char **line);
void				check_map_2d(char *file, t_var *var);
int					hundle_key(t_var *var);
int					key_press(int key, t_var *var);
int					key_release(int key, t_var *var);
long long			ft_atoi(const char *str);
void				*ft_memset(void *b, int c, size_t len);
char				**ft_split(char const *str, char c);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strtrim(const char *s, const char *set);
void				ft_putstr_fd(char *s, int fd);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *src);
size_t				ft_strlen(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					check_len_tab(char **tab);
int					check_two_str(char *rsl, char *src);
void				handle_sp(char *line, t_var *var);
int					max_len_1d(char **tab);
int					verify_eof(int fd, char *line, t_var *var);
int					hundle_line(int fd, char *line, t_var *var);
int					reverse_map(t_map *map);
void				get_tex_no(char *path_tex, char *line, t_var *var);
void				get_tex_so(char *path_tex, char *line, t_var *var);
void				get_tex_we(char *path_tex, char *line, t_var *var);
void				get_tex_ea(char *path_tex, char *line, t_var *var);
void				get_tex_sp(char *path_tex, char *line, t_var *var);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				draw_in_file(t_var *var);
void				ft_initaialize(t_var *var);
void				protect_data(t_var *var);
void				protect_ptr(t_var *var);
void				initial_player(t_var *var);
int					exit_win();
#endif
