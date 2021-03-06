/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:00:46 by stvalett          #+#    #+#             */
/*   Updated: 2017/02/06 15:22:56 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <time.h>
# include <grp.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define EACCESS    13
# define ENOENTT	2
# define MAX_OPT	255
# define MAX_PATH	4095
# define MOD		11
# define WHITE      "\033[37m"
# define RED		"\x1B[31m"
# define PINK		"\033[35m"
# define RESET		"\033[0m"
# define YELLOW		"\033[33m"
# define BLUE		"\x1B[34m"

typedef struct		s_dir
{
	struct stat		info;
	struct passwd	pwd;
	struct group	gid;
	struct tm		time;
	char			all_path[MAX_PATH];
	char			*pathdir;
	char			*name;
	char			*tmp;
	unsigned char	type;
	unsigned short	length;
	int				stat_current;
	int				stat_handle;
	int				size;
	int				size_lnk;
	int				size_uid;
	int				size_gid;
	int				size_min;
	int				size_maj;
}					t_dir;

typedef struct		s_opt
{
	char			*tab_opt[MAX_OPT];
	int				len_opt;
	int				o_option;
	int				o_no_format;
	struct stat		info;
	int				file;
	int				o_1;
	int				o_a;
	int				o_t;
	int				o_up_r;
	int				o_r;
	int				o_l;
	int				o_up_a;
	int				o_up_s;
	int				o_f;
	int				o_up_f;
	int				o_g;
	int				o_up_g;
	int				o_o;
	int				o_p;
	int				o_u;
}					t_opt;

typedef struct		s_mode
{
	char			str[MOD];
	char			*buff;
	char			**rigth;
}					t_mode;

t_opt				check_opt(int ac, char **a);
t_dir				check_error(char *av);
t_opt				init_opt(void);
void				valide_opt(t_opt *opt, char *av);
void				lstfile_2(int *k, int *count, t_dir *dir, char *name);
void				lstdir(char *av, t_opt *opt);
void				isdir_bis(int mode, char *name);
void				print_all(t_dir *current, int len, t_opt *opt, int flag);
void				ft_get_mode(t_dir *current, int l);
void				ft_free_mod(t_mode *mod);
void				ft_free_current(t_dir *current, int ret, int flag);
void				ft_link(t_dir *current);
void				ft_init_sort(t_dir *current, int len, t_opt *opt);
void				ft_sort_time_bis(t_dir *dir, int len, t_opt *opt);
void				ft_init_size(t_dir *current, t_opt *opt, int len);
void				ft_rev(t_opt *opt, int len);
void				ft_sort_bis(t_opt *opt, int len);
void				ft_sort_bis_u(t_opt *opt, int len);
void				ft_sort_size_bis(t_opt *opt, int len);
void				ft_total_block(t_dir *current, t_opt *opt, int len);
void				print_law(long date, t_opt *opt);
void				print_size(t_dir *dir, int size);
void				print_lnk(t_dir *dir, int size);
void				print_link(t_dir *dir, char *lnkpath, t_opt *opt);
void				print_link_colors(t_dir *dir, char *lnkpath, t_opt *opt);
void				print_uid(t_dir *dir, int size, t_opt *opt);
void				print_gid(t_dir *dir, int size, t_opt *opt);
void				print_name(t_dir *dir, t_opt *opt);
void				print_maj_min(t_dir *dir, int size_min, int size_maj);
void				print_filetype(char *name, int i, int *flag, t_opt *opt);
void				print_colors_1(char *name, t_opt *opt);
void				print_colors_2(char *name, t_opt *opt);
void				print_colors_3(char *name, t_opt *opt);
void				ft_error(int i, char *name);
void				ft_error_argc(char c);
int					ft_getmax_size(t_dir *dir, t_opt *opt, int len);
int					ft_getmax_lnk(t_dir *dir, t_opt *opt, int len);
int					ft_getmax_uid(t_dir *dir, t_opt *opt, int len);
int					ft_getmax_gid(t_dir *dir, t_opt *opt, int len);
int					ft_getmax_maj(t_dir *dir, t_opt *opt, int len);
int					ft_getmax_min(t_dir *dir, t_opt *opt, int len);
char				*mod_time(char *tmp);
int					ft_count_all(char *av, t_opt *opt);
int					ft_one_opt(char *str, char c);
int					ft_lendigit(int len);
int					fcmp(const char *s1, const char *s2);
int					print_or_not(char *name, t_opt opt);

#endif
