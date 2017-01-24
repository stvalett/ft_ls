/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:10:03 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/23 17:10:22 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void		ft_reverse(t_dir *current, int len, t_opt *opt)
{
	t_dir 	tmp;
	int		i;

	if (opt->o_r == 0)
		return ;
	else
	{
		i = 0;
		while (i < len)
		{
			tmp = current[i];
			current[i] = current[len - 1];
			current[len - 1] = tmp;
			i++;
			len--;
		}
	}
}

static void		ft_sort_alpha(t_dir *current, int len)
{
	t_dir 	tmp;
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
			if ((ft_strcmp((current + i)->name, (current + i + 1)->name) > 0))
			{
				tmp = current[i];
				current[i] = current[i + 1];
				current[i + 1] = tmp;
				flag = 1;
			}
			i++;
		}
		len--;
	}
}

static void		ft_sort_time(t_dir *current, int len, t_opt *opt)
{
	t_dir 	tmp;
	int		i;
	int		flag;

	if (opt->o_t == 0)
		return ;
	i = 0;
	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (i < len - 1)
		{
			if ((current + i)->info.st_mtime < (current + i + 1)->info.st_mtime)
			{
				tmp = current[i];
				current[i] = current[i + 1];
				current[i + 1] = tmp;
				flag = 1;
			}
			i++;
		}
		len--;
	}
}

void	ft_init_sort(t_dir *current, int len, t_opt *opt)
{
	ft_sort_alpha(current, len);
	ft_sort_time(current, len, opt);
	ft_reverse(current, len, opt);
}