#include "ft_select.h"

void	ft_help(t_select *select)
{
	tputs(tgetstr("cl", NULL), 1, &ft_putcharinterr);
	ft_putstr_fd(ANSI_COLOR_BLUE, 2);
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

void	ft_gohomeelem(t_select *select)
{
	select->start = select->elems;
	select->pos = select->elems;
	ft_winsize(select);
}

void	ft_goendelem(t_select *select)
{
	select->start = ft_dclist_at(select->elems, select->nb_elem - select->maxlin);
	ft_winsize(select);
	while (select->pos != select->elems->prev)
		ft_gonextline(select);
}
