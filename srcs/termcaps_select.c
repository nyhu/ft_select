#include "ft_select.h"

void	ft_print_mode(t_select *select, t_dclist *rabbit)
{
	if (select->tstate && rabbit == select->pos)
		ft_putstr_fd(ANSI_UNDERLINE, FD);
	else if (rabbit == select->pos)
		tputs(tgetstr("us", NULL), 1, &ft_putcharinterr);
	if (select->tstate && rabbit->data_size & 1)
		ft_putstr_fd(ANSI_REVERSEVID, FD);
	else if (rabbit->data_size & 1)
		tputs(tgetstr("mr", NULL), 1, &ft_putcharinterr);
}

void	ft_del_line(t_select *select)
{
	if (select->tstate)
		 ft_putstr_fd(CLEAR_LINE, FD);
	else
		tputs(tgetstr("dl", NULL), 1, &ft_putcharinterr);
}

void	ft_clear(t_select *select)
{
	if (select->tstate)
		 ft_putstr_fd(CLEAR, FD);
	else
		tputs(tgetstr("cl", NULL), 1, &ft_putcharinterr);
}

void	ft_tgoto(t_select *select, int col, int row)
{
	if (select->tstate)
	{
		++row;
		++col;
		FT_PUTSTRFD("\x1b[", ft_st_itoa(row), ";", FD);
		ft_putstr_fd(ft_st_itoa(col), FD);
		ft_putstr_fd("H", FD);
	}
	else
		tputs(tgoto(tgetstr("cm", NULL), col, row), 1, &ft_putcharinterr);
}

void	ft_prepcursor(t_select *select, int mode)
{
	(void)select;
	if (mode)
	{
		tputs(tgetstr("ti", NULL), 1, &ft_putcharinterr);
		if (!(CURSOR_VISIBILITY))
			tputs(tgetstr("vi", NULL), 1, &ft_putcharinterr);
	}
	else
	{
		if (!(CURSOR_VISIBILITY))
			tputs(tgetstr("ve", NULL), 1, ft_putcharinterr);
		tputs(tgetstr("te", NULL), 1, ft_putcharinterr);
	}
}
