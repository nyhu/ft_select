#include "ft_select.h"

int			ft_putcharinterr(int i)
{
	char		c;

	c = i;
	ft_putchar_fd(c, FD);
	return(c);
}

void		ft_mathcol(t_select *select)
{
	select->maxcol = select->nb_col / select->len_max;
	select->maxlin = (select->nb_elem / select->maxcol) + 1;
	if (select->maxlin > select->nb_lin)
		select->maxlin = select->nb_lin;
}

void		ft_winsize(t_select *select)
{
	t_winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	select->nb_col = win.ws_col;
	select->nb_lin = win.ws_row;
	ft_mathcol(select);
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
