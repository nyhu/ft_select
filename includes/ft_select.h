/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:23:28 by tboos             #+#    #+#             */
/*   Updated: 2016/05/23 08:41:37 by tboos            ###   ########.fr       */
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

/*
** Fell free to change SEARCH_SIZE.
** CURSOR_VISIBILITY on 0 will make cursor disapear, any other make it visible.
*/
# define CURSOR_VISIBILITY 0
# define SEARCH_SIZE 30
# define FT_PUTSTRFD ft_putstr_str_str_fd
# define LIST_ERR "malloc error while crafting list"
# define TERM_ERR "unable to get current terminal name in environnement"
# define CTERM_ERR "unable to set terminal properly"
# define READ_ERR "an error append during read"
# define MAX_ELEM 0xFFFF
# define MAXE_ERR "to much elements to be contaigned on display"
# define FD 2
# define CLEAR "\x1b[2J"
# define CLEAR_LINE "\x1b[K"
# define ANSI_UNDERLINE "\x1b[4m"
# define ANSI_REVERSEVID "\x1b[7m"

typedef struct stat		t_stat;
typedef struct winsize	t_winsize;
typedef struct termios	t_termios;
typedef unsigned short	t_ushort;
typedef struct	s_select
{
	char		tstate;
	char		*term;
	t_dclist	*elems;
	t_dclist	*pos;
	t_dclist	*start;
	t_termios	termios_backup;
	char		buf[9];
	char		search[SEARCH_SIZE];
	t_ushort	collin;
	t_ushort	maxlin;
	t_ushort	maxcol;
	t_ushort	len_max;
	t_ushort	nb_elem;
}				t_select;

/*
** main && keyparsing.c
*/
void			ft_exit_init(t_select *select, char *err);
int				ft_scmp(void *data1, void *data2);
int				ft_keyparse(t_select *select);
void			ft_elemprint(t_select *select, t_dclist *rabbit);
void			ft_listprint(t_select *select);
/*
** termcaps_select.c
*/
void			ft_print_mode(t_select *select, t_dclist *rabbit);
void			ft_del_line(t_select *select);
void			ft_clear(t_select *select);
void			ft_tgoto(t_select *select, int col, int row);
void			ft_prepcursor(t_select *select, int mode);
/*
** signal_select.c
*/
t_select		*ft_save_select(t_select *select);
void			ft_signalhandle(int i);
void			ft_signals(void);
/*
** add_del.c
*/
void			ft_delelem(t_select *select);
void			ft_select_all(t_select *select);
void			ft_deselect_all(t_select *select);
void			ft_selectelem(t_select *select);
/*
** arrow_select.c
*/
void			ft_nextcoord(t_select *select);
void			ft_goprevline(t_select *select);
void			ft_gonextline(t_select *select);
void			ft_gonextcol(t_select *select);
void			ft_goprevcol(t_select *select);
/*
** free_select.c
*/
void			ft_escape_select(t_select *select);
void			ft_freedata(void *data, size_t size);
void			ft_print_freedata(void *data, size_t size);
void			ft_exit_init(t_select *select, char *err);
/*
** termwin.c
*/
int				ft_putcharinterr(int i);
int				ft_termios_handle(t_select *select, int mode);
void			ft_winsize(t_select *select);
/*
** bonus_select.c
*/
void			ft_help(t_select *select);
void			ft_print_search(t_select *select);
void			ft_cur_search(t_select *select);
void			ft_gohomeelem(t_select *select);
void			ft_goendelem(t_select *select);

#endif
