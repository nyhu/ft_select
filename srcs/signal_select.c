#include "ft_select.h"

static void	ft_stop_cont(t_select *select, int mode)
{
	char	c[2];

	if (mode)
	{
		c[0] = select->termios_backup.c_cc[VSUSP];
		c[1] = 0;
		signal(SIGTSTP, SIG_DFL);
		ft_clear(select);
		ft_prepcursor(select, 0);
		ioctl(0, TIOCSTI, c);
		ft_termios_handle(select, 0);
	}
	else
	{
		if (!ft_termios_handle(select, 1))
			ft_exit_init(select, CTERM_ERR);
		ft_prepcursor(select, 1);
		ft_clear(select);
		select->start = select->elems;
		ft_winsize(select);
	}
}

void		ft_signalhandle(int i)
{
	t_select *select;

	select = ft_save_select(NULL);
	if (i == SIGWINCH)
		ft_winsize(select);
	if (i == SIGTSTP || i == SIGSTOP || i == SIGCONT)
		ft_stop_cont(select, i == SIGTSTP ? 1 : i == SIGSTOP ? 1 : 0);
	if (i == SIGINT || i == SIGQUIT || i == SIGTERM)
		ft_escape_select(select);
}

void		ft_signals(void)
{
	signal(SIGWINCH, &ft_signalhandle);
	signal(SIGINT, &ft_signalhandle);
	signal(SIGQUIT, &ft_signalhandle);
	signal(SIGTERM, &ft_signalhandle);
	signal(SIGTSTP, &ft_signalhandle);
	signal(SIGSTOP, &ft_signalhandle);
	signal(SIGCONT, &ft_signalhandle);
}

t_select	*ft_save_select(t_select *select)
{
	static t_select	*save = NULL;

	if (select)
		save = select;
	return (save);
}

