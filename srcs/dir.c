/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:58:25 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/27 09:58:44 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

static int		get_addpath(t_dir *current, char path[MAX_PATH])
{
	ft_strcpy(path, current->pathdir);
	ft_strcat(path, "/");
	ft_strcat(path, current->name);
	return (0);
}

static void		isdir(t_dir *current, t_opt *opt)
{
	char	*d_name;
	char	path[MAX_PATH];

	d_name = current->name;
	if (current->type == DT_DIR)
	{
		if ((ft_strcmp(d_name, "..") != 0 && ft_strcmp(d_name, ".") != 0))
		{
			get_addpath(current, path);
			if (opt->len_opt == 1)
			{
				ft_putchar('\n');
				ft_putstr(path);
				ft_putendl(":");
			}
			stat(d_name, &current->info);
			isdir_bis(current, d_name);
			lstdir(current->all_path, *opt);
		}
	}
}

static t_dir	get_path(char *av, struct dirent *file)
{
	t_dir	current;
	int		path_length;

	current.pathdir = ft_strdup(av);
	current.name = ft_strdup(file->d_name);
	current.type = file->d_type;
	get_addpath(&current, current.all_path);
	path_length = ft_strlen(current.all_path);
	if (path_length >= MAX_PATH)
	{
		ft_putendl("Le chemin d'acces est trop grand");
		exit(1);
	}
	current.stat_current = (stat(current.all_path, &current.info) < 0) ? 0 : 1;
	current.stat_handle = (lstat(current.all_path, &current.info) < 0) ? 0 : 1;
	return (current);
}

static void		lstdir2(t_dir *current, t_opt *opt, int i, char *av)
{
	int				ret;
	static	int		count;

	ret = 0;
	if (++count == 1 && opt->len_opt == 1)
		print_all(&current[0], i, opt, 0);
	else if (count >= 1 && opt->len_opt > 1)
	{
		if (count >= 2)
			ft_putchar('\n');
		if ((current[0].pathdir) == NULL)
			ft_putstr(av);
		else if (ft_strcmp(current[0].pathdir, "./") == 0 && opt->len_opt == 2)
			ft_putstr(".");
		else if (ft_strcmp(current[0].pathdir, ".") == 0 && count >= 2)
			ft_putstr("./");
		else
			ft_putstr(current[0].pathdir);
		ft_putendl(":");
		print_all(&current[0], i, opt, 0);
	}
	else
		print_all(&current[0], i, opt, 0);
	while (ret < i && opt->o_up_r == 1)
		isdir(&current[ret++], opt);
}

void			lstdir(char *av, t_opt opt)
{
	int				i;
	t_dir			*current;
	DIR				*path;
	struct dirent	*file;

	i = 0;
	if ((current = (t_dir *)malloc(sizeof(t_dir) *
					ft_count_all(av, &opt))) == NULL)
		exit(1);
	if ((path = opendir(av)) == NULL)
	{
		ft_free_current(current, i, 0);
		return ;
	}
	while ((file = readdir(path)) != NULL)
		if (!opt.o_a && !opt.o_up_a && !opt.o_f)
		{
			if (file->d_name[0] != '.')
				current[i++] = get_path(av, file);
		}
		else
			current[i++] = get_path(av, file);
	lstdir2(current, &opt, i, av);
	closedir(path);
	ft_free_current(current, i, 0);
}
