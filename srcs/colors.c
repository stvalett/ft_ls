/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 12:36:32 by stvalett          #+#    #+#             */
/*   Updated: 2017/02/05 18:14:39 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

void	print_colors_3(char *name, t_opt *opt)
{
    if (opt->o_up_g && opt->o_up_f && !opt->o_p)
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
        if (!opt->o_p)
            ft_putendl("@");
    }
}

void	print_colors_2(char *name, t_opt *opt)
{
    if (opt->o_up_g && opt->o_up_f && !opt->o_p)
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
        if (!opt->o_p)
            ft_putendl("*");
    }
}

void	print_colors_1(char *name, t_opt *opt)
{
    if ((opt->o_up_g && opt->o_up_f)
            || (opt->o_p && opt->o_up_g))
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

void	print_link_colors(t_dir *dir, char *lnkpath, t_opt *opt)
{
    int		path_size;
    char	buf[MAX_PATH];

    ft_putstr(PINK);
    ft_putstr(dir->name);
    ft_putstr(RESET);
    if (opt->o_up_f && !opt->o_p)
        ft_putstr("@");
    if ((path_size = readlink(lnkpath, buf, MAX_PATH)) < 0)
        return ;
    buf[path_size] = '\0';
    ft_putstr(" -> ");
    ft_putendl(buf);
}

static int max_len_word(t_dir *current, int len)
{
    int i;
    int max_word;
    int count;

    i = -1;
    max_word = 0;
    while (++i < len)
    {
        count = ft_strlen(current[i].name);
        if (count > max_word)
            max_word = count;
    }
    return (max_word);
}

void    display_simple(t_dir *current, int len, t_opt *opt)
{
    struct winsize  sz;
    int             i;
    int             flag;
    int             i2;
    int             cols;

    if (opt->o_l || opt->o_g || opt->o_u)
        return ;
    max_len_word(current, len);
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &sz);
    cols = sz.ws_col;
    cols /= max_len_word(current, len);
    i = -1;
    flag = 0;
    i2 = 0;
    while (++i < len)
    {
        if (flag == 1)
            i2 = 0;
        if ((i % cols) == 0)
        {
            if (flag)
                ft_putstr(current[i2].name);
            else
                ft_putstr(current[i].name);
            ft_putchar('\n');
            flag = 1;
        }
        else
            ft_putchar(' ');
        if (flag && current[i + 1].name != NULL)
            ft_putstr(current[i2 + 1].name);
        else
            ft_putstr(current[i + 1].name);
        flag = 0;
    }
    ft_putchar('\n');
}
