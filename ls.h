/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:00:46 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/24 15:03:41 by stvalett         ###   ########.fr       */
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
# include "libft/libft.h"
# include <stdio.h>

# define EACCESS    13
# define ENOENTT	2
# define MAX_OPT	255
# define MAX_PATH	4095
# define MOD		11
# define WHITE      "\033[37m"
# define RED		"\x1B[31m"
# define GREY       "\032[0m"
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
	char            *tmp;
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
	int				file;
	int				o_nopt;
	int				o_1;
	int				o_a;
	int				o_t;
	int				o_R;
	int				o_r;
	int				o_l;
	int				o_d;
	int             o_F;
}					t_opt;

typedef struct      s_mode
{
	char            str[MOD];
	char            *buff;
	char            **rigth;
}                   t_mode;

t_opt				check_opt(int ac, char **av);
void				lstdir(char *av, t_opt opt);
void				print_all(t_dir *current, int len, t_opt *opt, int flag);
void				ft_get_mode(t_dir *current, int l);
void				ft_free_mod(t_mode *mod);
void				ft_free_current(t_dir *current, int ret, int flag);
void				ft_link(t_dir *current);
void				ft_init_sort(t_dir *current, int len, t_opt *opt);
void				ft_init_size(t_dir *current, t_opt *opt, int len);
void				print_law(long date, t_opt *opt);
void				print_size(t_dir *dir, int size);
void				print_lnk(t_dir *dir, int size);
void                print_link(t_dir *dir, char *lnkpath, t_opt *opt);
void				print_uid(t_dir *dir, int size);
void				print_gid(t_dir *dir, int size);
void                print_name(t_dir *dir, t_opt *opt);
void				print_maj_min(t_dir *dir, int size_min, int size_maj);
void				print_filetype(char *name, int i);
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

#endif
