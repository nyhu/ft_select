#include "ft_select.h"

void		ft_signalhandle(int i)
{
	if (i == SIGWINCH)
		ft_winsize(ft_save_select(NULL));
}

void		ft_signals(void)
{
	signal(SIGWINCH, &ft_signalhandle);
//	signal(SIGSEGV, segv);
//	signal(SIGTSTP, tempstop);
//	signal(SIGCONT, resume);
//	signal(SIGSTOP, stop);
}

t_select	*ft_save_select(t_select *select)
{
	static t_select	*save = NULL;

	if (select)
		save = select;
	return (save);
}

