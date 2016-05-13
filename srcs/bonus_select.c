#include "ft_select.h"

void	ft_gohomeelem(t_select *select)
{
//dprintf(2, "yop");
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
