/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 18:45:29 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/01/15 23:18:02 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "../includes/get_next_line.h"

typedef struct		s_image
{
	unsigned char	**str;
	int				*tab;
	int				*pab;
	unsigned char	*start;
}					t_image;
typedef struct		s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	t_image			im_str;
}					t_data;
typedef	struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;
typedef	struct		s_couple
{
	t_point			a;
	t_point			b;
}					t_couple;
char				**ft_strparse(char *str, char c);
int					col_num(char *str);
int					file_nums(char *name, int *line, int *col);
int					max(int a, int b);
int					ft_maxz(int *tab, int col, int lin);
int					ft_minz(int *tab, int col, int lin);
void				ft_init_im(unsigned char **tmp, unsigned char *str,
		int len);
int					errors(int argc, int **tab);
int					**generate_tabs(int c_num, int l_num);
void				init_free(int *i, int *j, char *str, char **temp);
int					populate(int **out, char *name, int c_num, int l_num);
int					**into_tab(char *name);
int					deal_key_sub_small(int key, void *param, int *vals);
int					deal_key_sub_large(int key, void *param, int *vals);
int					deal_key(int key, void *param);
void				draw_image_sub_sub(unsigned char **str, int *tab,
		int *pab, int i);
void				draw_image_sub(unsigned char **str, int *tab, int *pab);
void				draw_image(unsigned char **str, int *tab, int **cab);
void				invert_points(t_couple *bal);
void				fill_pos_y(unsigned char **str, t_couple po, int *tab,
		int k);
void				fill_pos_x(unsigned char **str, t_couple po, int *tab,
		int k);
void				draw_line_pos(unsigned char **str, t_couple po, int *tab);
void				fill_xneg_y(unsigned char **str, t_couple po, int *tab,
		int k);
void				fill_xneg_x(unsigned char **str, t_couple po, int *tab,
		int k);
void				draw_line_xneg(unsigned char **str, t_couple po, int *tab);
void				fill_yneg_y(unsigned char **str, t_couple po, int *tab,
		int k);
void				fill_yneg_x(unsigned char **str, t_couple po, int *tab,
		int k);
void				draw_line_yneg(unsigned char **str, t_couple po, int *tab);
void				draw_line(unsigned char **str, t_couple po, int *tab);
void				color_change(int *vals, void *param);
void				filling(int *vals, void *param);
void				unfilling(int *vals, void *param);
void				para_proj(int *vals, void *param);
void				iso_proj(int *vals, void *param);
void				left(int *vals, void *param);
void				right(int *vals, void *param);
void				up(int *vals, void *param);
void				down(int *vals, void *param);
void				thirty(int *vals, void *param);
void				sixty(int *vals, void *param);
void				zoom_in(int *vals, void *param);
void				zoom_out(int *vals, void *param);
void				raise(int *vals, void *param);
void				lower(int *vals, void *param);
char				**ft_strparse(char *str, char c);
void				generate_points(int *tab, t_point *a, int i, int *pab);
double				min(double a, double b);
int					**double_prec(int *in, int wid, int len);
int					diff_vals(int *tab, int col, int lin);
int					from_old(int x, int y, int *in, int col);
int					hor(int x, int y, int *in, int col);
int					ft_ptrchr(char *str, char c);
int					ver(int x, int y, int *in, int col);
int					front_sp(char *str, char c);
int					diag(int x, int y, int *in, int col);
int					back_sp(char *str, char c, int len);
int					*prec_mode(int argc, char **argv);
int					**doubled_arr(int i, int **tab);
#endif
