/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:01:36 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/23 17:02:01 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static t_dir    check_error(char *av)
{
	t_dir dir;

	if ((stat(av, &dir.info)) == 0
			&& !(dir.info.st_mode & S_IRWXU))
	{
		ft_error(1, av);
		dir.name = ft_strdup("NULL");
	}
	else if ((lstat(av, &dir.info)) == -1)
	{
		ft_error(2, av);
		dir.name = ft_strdup("NULL");
	}
	else
		dir.name = ft_strdup(av);
	return (dir);
}

static void  print_only(t_dir *dir, int len, t_opt *opt)
{
	int i;

	i = 0;
	ft_init_sort(dir, len, opt);
	ft_init_size(dir, opt, len);
	while (i < len)
	{
		if (ft_strcmp(dir[i].name, "NULL") == 0)
			;
		else
		{
			if (opt->o_l == 1)
			{
				ft_get_mode(dir , i);
				print_lnk(&dir[i], dir->size_lnk);
				print_uid(&dir[i], dir->size_uid);
				print_gid(&dir[i], dir->size_gid);
				print_size(&dir[i], dir->size);
				print_law(dir[i].info.st_mtime, opt);
				print_link(&dir[i], dir[i].name, opt);
			}
			else
				print_name(&dir[i], opt);
		}
		i++;
	}
}

static void		ft_sort_file(t_opt *opt, int len)
{
	char 	*tmp;
	int		i;
	int		flag;

	i = 0;
	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (i < len - 1)
		{
			if ((ft_strcmp(opt->tab_opt[i], opt->tab_opt[i + 1]) > 0))
			{
				tmp = opt->tab_opt[i];
				opt->tab_opt[i] = opt->tab_opt[i + 1];
				opt->tab_opt[i + 1] = tmp;
				flag = 1;
			}
			i++;
		}
		len--;
	}
}

static t_dir	*lstfile(int ac, char **av, int *k, int *count)
{
	DIR     *path;
	t_opt	opt;
	t_dir   *dir;
	int		i;

	dir = NULL;
	opt = check_opt(ac, av);
	if ((dir = malloc(sizeof(t_dir) * opt.len_opt)) == NULL)
		exit(1);
	i = -1;
	ft_sort_file(&opt, opt.len_opt);
	while (++i < opt.len_opt)
	{
		if ((path = opendir(opt.tab_opt[i])) == NULL)
		{
			dir[*k] = check_error(opt.tab_opt[i]);
			*k = *k + 1;
		}
		else
		{
			*count = *count + 1;
			closedir(path);
		}
	}
	return (dir);
}

int		main(int ac, char **av)
{
	t_opt	opt;
	t_dir	*dir;
	int		i;
	int		k;
	int		count;

	k = 0;
	count = 0;
	opt = check_opt(ac, av);
	dir = lstfile(ac, av, &k, &count);
	print_only(dir, k, &opt);
	if (k != 0 && opt.len_opt > 1 && count != 0)
		ft_putchar('\n');
	ft_free_current(dir, opt.len_opt, 1);
	i = 0;
	while (i < opt.len_opt)
		lstdir(opt.tab_opt[i++], opt);
	return (0);
}
