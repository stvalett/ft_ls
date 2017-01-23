/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:01:18 by stvalett          #+#    #+#             */
/*   Updated: 2016/12/07 11:18:02 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 19	
# define CHAR		'\n'

typedef	struct		s_line
{
	int				fd;
	int				ret;
	char			*first;
	char			*buff;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
