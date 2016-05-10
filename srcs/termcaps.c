#include "ft_select.h"

void	ft_mvrightcol(t_select *select)
{
	int		i;

	i = select->len_max;
	while (i--)
		tputs(tgetstr("nd", NULL), 1, &ft_putcharinterr);
}

void	ft_mvuplin(t_select *select)
{
	int		i;

	i = select->maxlin;
	while (i--)
		tputs(tgetstr("up", NULL), 1, &ft_putcharinterr);
	ft_mvrightcol(select);
}

void	ft_mvdolin(t_select *select)
{
	(void *)select;
	tputs(tgetstr("do", NULL), 1, &ft_putcharinterr);
}
