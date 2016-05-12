/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:23:28 by tboos             #+#    #+#             */
/*   Updated: 2016/05/11 14:36:45 by tboos            ###   ########.fr       */
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
# ifdef LINUX
#  include "keys_linux.h"
# else
#  include "keys_mac.h"
# endif
# define FT_PUTSTRFD ft_putstr_str_str_fd
# define LIST_ERR "malloc error while crafting list"
# define TERM_ERR "unable to get current terminal name in env"
# define CTERM_ERR "unable to configure terminal"
# define READ_ERR "an error append during read"
# define FD 2

typedef struct winzise	t_winsize;
typedef struct termios	t_termios;
typedef unsigned short	t_ushort;
typedef struct	s_select
{
	t_dclist	*elems;
	t_dclist	*pos;
	t_termios	termios_backup;
	char		buf[9];
	t_ushort	nb_col;
	t_ushort	nb_lin;
	t_ushort	maxlin;
	t_ushort	maxcol;
	size_t		len_max;
	size_t		nb_elem;
	char		*term;
	int			fd;
}				t_select;

int				ft_putcharinterr(int i);
void			ft_exit_init(t_select *select, char *err);
int				ft_scmp(void *data1, void *data2);
int				ft_termios_handle(t_config *config, int mode);

#endif
