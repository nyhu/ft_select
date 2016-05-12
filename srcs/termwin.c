/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termwin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:44:10 by tboos             #+#    #+#             */
/*   Updated: 2016/05/11 14:44:19 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			ft_putcharinterr(int i)
{
	char		c;

	c = i;
	ft_putchar_fd(c, FD);
	return (c);
}

void		ft_winsize(t_select *select)
{
	t_winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	select->maxlin = win.ws_row - 1;
	select->maxcol = (win.ws_col - 1) / select->len_max;
	tputs(tgetstr("cl", NULL), 1, &ft_putcharinterr);
	ft_listprint(select);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, &ft_putcharinterr);
	select->collin = 0;
	while (ft_keyparse(select))
		;
}

int			ft_termios_handle(t_select *select, int mode)
{
	t_termios	shell;
	static char	state = 'n';

	if (mode && state == 'n')
	{
		if (tcgetattr(STDIN_FILENO, &(select->termios_backup)) == -1
		|| !ft_memcpy(&shell, &(select->termios_backup), sizeof(t_termios)))
			return (0);
		shell.c_lflag &= ~(ICANON | ECHO);
		shell.c_cc[VMIN] = 1;
		shell.c_cc[VTIME] = 0;
		if (tcsetattr(STDIN_FILENO, TCSADRAIN, &shell) == -1)
			return (0);
		state = 'y';
	}
	else if (state == 'y')
	{
		tcsetattr(STDIN_FILENO, TCSANOW, &(select->termios_backup));
		state = 'n';
	}
	return (1);
}
