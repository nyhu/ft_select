/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:23:28 by tboos             #+#    #+#             */
/*   Updated: 2016/03/29 20:28:49 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <sys/ioctl.h>
# include <term.h>
# include <curses.h>
# include <stdio.h>
# include <termios.h>
# include <fcntl.h>
# include <signal.h>
# include "libft.h"
# include "keys.h"
# define FT_PUTSTRFD ft_putstr_str_str_fd
# define LIST_ERR "malloc error while crafting list"
# define TERM_ERR "unable to get current terminal name in env"
# define TERM_ERR "unable to configure terminal"

typedef struct termios	t_termios;
typedef struct	s_select
{
	t_dclist	*elems;
	size_t		len_max;
	size_t		nb_elem;
	char		*term;
	t_termios	termios_backup;
	int			fd;
}				t_select;

void	ft_exit_init(t_select *select, char *err);
int		ft_scmp(void *data1, void *data2)
int		ft_termios_handle(t_config *config, int mode);

#endif
