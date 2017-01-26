/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:13:59 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/26 20:10:25 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		fcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_getmax_maj(t_dir *dir, t_opt *opt, int len)
{
	int	i;
	int count;
	int	countmax;

	count = 0;
	countmax = 0;
	i = -1;
	while (++i < len)
		if (!opt->o_a && !opt->o_f)
		{
			if ((ft_strcmp((dir + i)->name, ".")) != 0
					&& ((ft_strcmp((dir + i)->name, "..")) != 0
						&& (opt->o_l || opt->o_g || opt->o_o)))
				count = ft_lendigit((major((dir + i)->info.st_rdev)));
			if (count > countmax)
				countmax = count;
		}
		else
		{
			count = ft_lendigit(major((dir + i)->info.st_rdev));
			if (count > countmax)
				countmax = count;
		}
	return (countmax);
}

int		ft_getmax_min(t_dir *dir, t_opt *opt, int len)
{
	int	i;
	int count;
	int	countmax;

	count = 0;
	countmax = 0;
	i = -1;
	while (++i < len)
		if (!opt->o_a && !opt->o_f)
		{
			if (((ft_strcmp((dir + i)->name, ".")) != 0
						&& ((ft_strcmp((dir + i)->name, "..")) != 0
							&& (opt->o_l || opt->o_g || opt->o_o))))
				count = ft_lendigit(minor((dir + i)->info.st_rdev));
			if (count > countmax)
				countmax = count;
		}
		else
		{
			count = ft_lendigit(minor((dir + i)->info.st_rdev));
			if (count > countmax)
				countmax = count;
		}
	return (countmax);
}
