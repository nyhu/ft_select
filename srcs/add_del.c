#include "ft_select.h"

void	ft_delelem(t_select *select)
{
	t_dclist *kill;

	kill = select->pos;
	if (kill == select->elems)
		select->elems = kill->next;
	if (select->nb_elem > 1)
	{
		select->pos = kill->next;
		select->pos->prev = kill->prev;
		kill->prev->next = select->pos;
		nb_elem--;
		free(kill);
		ft_winsize;
	}
	else
	{
		select->elems = NULL;
		free(kill);
		ft_exit_init(select, NULL);
	}
}

void	ft_gohomeelem(t_select *select)
{
	select->pos = select->elems;
}

void	ft_goendelem(t_select *select)
{
	select->pos = select->elems->prev;
}
