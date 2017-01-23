/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:00:05 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/23 18:44:23 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static t_mode	*ft_init_mod(void)
{
	t_mode	*mod;

	if ((mod = (t_mode *)malloc(sizeof(t_mode))) == NULL)
		return (NULL);
	mod->buff = "--- --x -w- -wx r-- r-x rw- rwx";
	mod->rigth = ft_strsplit(mod->buff, ' ');
	return (mod);
}

static void ft_cal_mode(t_mode *mod, int mode, int *i, int *j)
{
	while (*i >= 1 && *i < 4 && *j < 3)
	{
		mod->str[*i] = mod->rigth[(mode >> 6) & 0X07][*j];
		mod->str[*i] = mod->rigth[(mode >> 6) & 0X07][*j];
		mod->str[*i] = mod->rigth[(mode >> 6) & 0X07][*j];
		*i = *i + 1;
		*j = *j + 1;
	}
	while (*i >= 4 && *i < 7 && *j < 3)
	{
		mod->str[*i] = mod->rigth[(mode >> 3) & 0X07][*j];
		mod->str[*i] = mod->rigth[(mode >> 3) & 0X07][*j];
		mod->str[*i] = mod->rigth[(mode >> 3) & 0X07][*j];
		*i = *i + 1;
		*j = *j + 1;
	}
	while (*i >= 7 && *i < 10 && *j < 3)
	{
		mod->str[*i] = mod->rigth[mode & 0X07][*j];
		mod->str[*i] = mod->rigth[mode & 0X07][*j];
		mod->str[*i] = mod->rigth[mode & 0X07][*j];
		*i = *i + 1;
		*j = *j + 1;
	}
}

static void	ft_more_mode(t_mode *mod, t_dir *current, int i)
{
	if (current->info.st_mode & S_ISVTX && current->info.st_mode & S_IXOTH)
		mod->str[9] = 't';
	else if (current->info.st_mode & S_ISVTX && !(current->info.st_mode & S_IXOTH))
		mod->str[9] = 'T';
	if (current->info.st_mode & S_ISUID && current->info.st_mode & S_IXUSR)
		mod->str[3] = 's';
	else if (current->info.st_mode & S_ISUID && !(current->info.st_mode & S_IXUSR))
		mod->str[3] = 'S';
	if (current->info.st_mode & S_ISGID && current->info.st_mode & S_IXGRP)
		mod->str[6] = 's';
	else if (current->info.st_mode & S_ISGID && !(current->info.st_mode & S_IXGRP))
		mod->str[6] = 'S';
	mod->str[i] = '\0';
	ft_putstr(mod->str);
	write(1, "  ", 2);
	ft_free_mod(mod);
}

static void	ft_get_mode2(t_dir *dir, t_mode *mode)
{
	if (S_ISLNK(dir->info.st_mode))
		mode->str[0] = 'l';
	else if (S_ISDIR(dir->info.st_mode))
		mode->str[0] = 'd';
	else if (S_ISFIFO(dir->info.st_mode))
		mode->str[0] = 'p';
	else if (S_ISCHR(dir->info.st_mode))
		mode->str[0] = 'c';
	else if (S_ISBLK(dir->info.st_mode))
		mode->str[0] = 'b';
	else if (S_ISSOCK(dir->info.st_mode))
		mode->str[0] = 's';
	else
		mode->str[0] = '-';
}

void	ft_get_mode(t_dir *current, int l)
{
	t_mode	*mod;
	int 	i;
	int		j;

	mod = ft_init_mod();
	ft_get_mode2(&current[l], mod);
	i = 1;
	if (i >= 1 && i < 4)
	{
		j = 0;
		ft_cal_mode(mod, current[l].info.st_mode, &i, &j);
	}
	if (i >= 4 && i < 7)
	{
		j = 0;
		ft_cal_mode(mod, current[l].info.st_mode, &i, &j);
	}
	if (i >= 7 && i < 10)
	{
		j = 0;
		ft_cal_mode(mod, current[l].info.st_mode, &i, &j);
	}
	ft_more_mode(mod, current, i);
}
