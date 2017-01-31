/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 12:36:32 by stvalett          #+#    #+#             */
/*   Updated: 2017/01/31 18:05:10 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

void	print_colors_3(char *name, t_opt *opt)
{
	if (opt->o_up_g && opt->o_up_f)
	{
		ft_putstr(PINK);
		ft_putstr(name);
		ft_putstr(RESET);
		ft_putendl("@");
	}
	else if (opt->o_up_g)
	{
		ft_putstr(PINK);
		ft_putendl(name);
		ft_putstr(RESET);
	}
	else
	{
		ft_putstr(name);
		ft_putendl("@");
	}
}

void	print_colors_2(char *name, t_opt *opt)
{
	if (opt->o_up_g && opt->o_up_f)
	{
		ft_putstr(RED);
		ft_putstr(name);
		ft_putendl("*");
		ft_putstr(RESET);
	}
	else if (opt->o_up_g)
	{
		ft_putstr(RED);
		ft_putendl(name);
		ft_putstr(RESET);
	}
	else
	{
		ft_putstr(name);
		ft_putendl("*");
	}
}

void	print_colors_1(char *name, t_opt *opt)
{
	if (opt->o_up_g && opt->o_up_f)
	{
		ft_putstr(BLUE);
		ft_putstr(name);
		ft_putendl("/");
		ft_putstr(RESET);
	}
	else if (opt->o_up_g)
	{
		ft_putstr(BLUE);
		ft_putendl(name);
		ft_putstr(RESET);
	}
	else
	{
		ft_putstr(name);
		ft_putendl("/");
	}
}
