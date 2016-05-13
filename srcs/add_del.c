/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:43:35 by tboos             #+#    #+#             */
/*   Updated: 2016/05/11 14:43:36 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_escape_select(t_select *select)
{
	if (select->elems)
		ft_dclstdel(&(select->elems), &ft_freedata);
	select->elems = NULL;
	ft_exit_init(select, NULL);
}

void	ft_selectelem(t_select *select)
{
	if (!(select->pos->data_size))
		select->pos->data_size = 1;
	else
		select->pos->data_size = 0;
	ft_gonextline(select);
}

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
		select->nb_elem--;
		free(kill);
		ft_winsize(select);
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
