#include "ft_select.h"

void	ft_help(t_select *select)
{
	ft_clear(select);
	ft_putstr_fd(ANSI_COLOR_GREEN, 2);
	ft_putstr_fd(HELP_PAGE1, 2);
	ft_putstr_fd(HELP_PAGE2, 2);
	ft_putstr_fd(HELP_PAGE3, 2);
	ft_putstr_fd(HELP_PAGE4, 2);
	ft_putstr_fd(HELP_PAGE5, 2);
	ft_putstr_fd(HELP_PAGE6, 2);
	ft_putstr_fd(HELP_PAGE7, 2);
	ft_putstr_fd(HELP_PAGE8, 2);
	ft_putstr_fd(ANSI_COLOR_CYAN, 2);
	ft_putstr_fd(HELP_PAGE9, 2);
	ft_putstr_fd(HELP_PAGE10, 2);
	ft_putstr_fd(HELP_PAGE11, 2);
	ft_putstr_fd(HELP_PAGE12, 2);
	ft_putstr_fd(HELP_PAGE13, 2);
	ft_putstr_fd(HELP_PAGE14, 2);
	ft_putstr_fd(HELP_PAGE15, 2);
	if (read(0, select->buf, 8) < 0)
		ft_exit_init(select, READ_ERR);
	ft_winsize(select);
}

void	ft_print_search(t_select *select)
{
	ft_tgoto(select, 0, select->maxlin);
	ft_del_line(select);
	if (select->search[0])
		FT_PUTSTRFD(ANSI_COLOR_GREEN, select->search, ANSI_COLOR_RESET, FD);
	else
		FT_PUTSTRFD(ANSI_COLOR_RED, HELP_MESS, ANSI_COLOR_RESET, FD);
	ft_tgoto(select, (select->collin / select->maxlin) * select->len_max,
	select->collin % select->maxlin);
}

void	ft_cur_search(t_select *select)
{
	static t_ushort	i = 0;
	t_dclist		*memo;

	if (i > 0 && !select->search[0])
		i = 0;
	else if ((i == SEARCH_SIZE - 1 || i == MAX_ELEM) && !(i = 0))
		ft_bzero(select->search, SEARCH_SIZE);
	else if (((ssize_t *)(select->buf))[0] == (ssize_t)DEL && i > 0)
		select->search[--i] = 0;
	else if (i == 0 || select->search[0])
		select->search[i++] = select->buf[0];
	ft_print_search(select);
	if (select->search[0])
	{
		memo = select->pos;
		ft_gonextline(select);
		while (select->pos != memo
			&& !ft_strstr(((char *)select->pos->data), select->search))
			ft_gonextline(select);
	}
}

void	ft_gohomeelem(t_select *select)
{
	select->start = select->elems;
	select->pos = select->elems;
	select->collin = 0;
	ft_tgoto(select, 0, 0);
	ft_winsize(select);
}

void	ft_goendelem(t_select *select)
{
	ft_gohomeelem(select);
	ft_goprevline(select);
}
