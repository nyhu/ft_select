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
# define CTERM_ERR "unable to configure terminal"
# define READ_ERR "an error append during read"
# define FD 2
# define CLF 0x0A //\n
# define SUP 0x7E335B1B //sup
# define CHT 0x09 //\t
# define DEL 0x7F //DEL
# define LEF 0x445B1B //left
# define RIG 0x435B1B //right
# define UPP 0x415B1B //up
# define DOW 0x425B1B //down
# define CLEF 0x44353B315B1B //CTRL left
# define CRIG 0x43353B315B1B //CTRL up
# define CUPP 0x41353B315B1B //CTRL right
# define CDOW 0x42353B315B1B //CTRL down
# define END 0x464F1B //end
# define HOM 0x484F1B //home
# define NUL 0x00 //\0

typedef struct winzise	t_winsize;
typedef struct termios	t_termios;
typedef unsigned short	t_ushort;
typedef struct	s_select
{
	t_dclist	*elems;
	t_dclist	*pos;
	t_termios	termios_backup;
	char		buf[9];
	t_ushort		maxel;
	t_ushort		maxcol;
	size_t		len_max;
	size_t		nb_elem;
	t_ushort		nb_col;
	t_ushort		nb_lin;
	char		*term;
	int			fd;
}				t_select;

int		ft_putcharinterr(int i);
void	ft_exit_init(t_select *select, char *err);
int		ft_scmp(void *data1, void *data2);
int		ft_termios_handle(t_config *config, int mode);

#endif
