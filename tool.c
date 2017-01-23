/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:10:27 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/23 17:22:35 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_free_mod(t_mode *mod)
{
	int k;

	k = 0;
	while (mod->rigth[k])
	{
		free(mod->rigth[k]);
		k++;
	}
	free(mod->rigth);
	free(mod);
}

int		ft_one_opt(char *str, char c)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

int     ft_lendigit(int len)
{
	int count;

	count = 0;
	while (len > 0)
	{
		len /= 10;
		count++;
	}
	if (count == 0)
		return (1);
	return (count);
}

void	ft_free_current(t_dir *current, int ret, int flag)
{
	int i;

	if (flag == 1)
	{
		i = 0;
		while (i < ret)
		{
			free(current[i].name);
			i++;
		}
		free(current);
	}
	else
	{
		i = 0;
		while (i < ret)
		{
			free(current[i].pathdir);
			free(current[i].name);
			i++;
		}
		free(current);
	}
}

int     ft_count_all(char *av, t_opt *opt)
{
	int             count;
	struct dirent   *file;
	DIR             *path;

	count = 0;
	if ((path = opendir(av)) == NULL)
		return (0);
	while ((file = readdir(path)) != NULL)
		count++;
	if (count == 2)
		opt->file = 1;
	else
		opt->file = 0;
	closedir(path);
	return (count);
}
