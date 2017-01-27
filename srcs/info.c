/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:00:05 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/27 09:59:04 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

static	t_mode	*ft_init_mod(void)
{
	t_mode	*mod;

	if ((mod = (t_mode *)malloc(sizeof(t_mode))) == NULL)
		return (NULL);
	mod->buff = "--- --x -w- -wx r-- r-x rw- rwx";
	mod->rigth = ft_strsplit(mod->buff, ' ');
	return (mod);
}

static	void	ft_cal_mode(t_mode *mod, int mode, int *i, int *j)
{
	*j = 0;
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

static	void	ft_more_mode(t_mode *mod, int mode)
{
	if (mode & S_ISVTX && mode & S_IXOTH)
		mod->str[9] = 't';
	else if (mode & S_ISVTX && !(mode & S_IXOTH))
		mod->str[9] = 'T';
	if (mode & S_ISUID && mode & S_IXUSR)
		mod->str[3] = 's';
	else if (mode & S_ISUID && !(mode & S_IXUSR))
		mod->str[3] = 'S';
	if (mode & S_ISGID && mode & S_IXGRP)
		mod->str[6] = 's';
	else if (mode & S_ISGID && !(mode & S_IXGRP))
		mod->str[6] = 'S';
}

static	void	ft_get_mode2(t_dir *dir, t_mode *mode)
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

void			ft_get_mode(t_dir *current, int l)
{
	t_mode	*mod;
	int		i;
	int		j;

	mod = ft_init_mod();
	ft_get_mode2(&current[l], mod);
	i = 1;
	if (i >= 1 && i < 4)
	{
		ft_cal_mode(mod, current[l].info.st_mode, &i, &j);
		ft_more_mode(mod, current[l].info.st_mode);
	}
	if (i >= 4 && i < 7)
	{
		ft_cal_mode(mod, current[l].info.st_mode, &i, &j);
		ft_more_mode(mod, current[l].info.st_mode);
	}
	if (i >= 7 && i < 10)
	{
		ft_cal_mode(mod, current[l].info.st_mode, &i, &j);
		ft_more_mode(mod, current[l].info.st_mode);
	}
	mod->str[i] = '\0';
	ft_putstr(mod->str);
	ft_free_mod(mod);
}
