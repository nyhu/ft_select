#include "ft_select.h"

void	ft_goprevline(t_select *select)
{
	select->pos = select->pos->prev;
}

void	ft_gonextline(t_select *select)
{
	select->pos = select->pos->next;
}

void	ft_gonextcol(t_select *select)
{
	select->pos = t_dclist_at(select->pos, select->maxlin);
}

void	ft_goprevcol(t_select *select)
{
	select->pos = t_dclist_at(select->pos, select->nb_elem - select->maxlin);
}
