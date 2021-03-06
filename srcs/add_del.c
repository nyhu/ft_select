/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:43:35 by tboos             #+#    #+#             */
/*   Updated: 2016/05/23 08:42:41 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_del_elem(t_select *select)
{
	t_dclist *kill;

	kill = select->pos;
	if (kill == select->elems)
	{
		select->elems = select->elems->next;
		select->start = select->elems;
	}
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

void		ft_delelem(t_select *select)
{
	if (((ssize_t *)(select->buf))[0] == DEL && select->search[0])
		ft_cur_search(select);
	else
		ft_del_elem(select);
}

void		ft_select_all(t_select *select)
{
	select->pos = select->elems->prev;
	select->start = select->elems;
	while (select->pos != select->elems)
	{
		select->pos->data_size |= 1;
		select->pos = select->pos->prev;
	}
	select->pos->data_size |= 1;
	ft_tgoto(select, 0, 0);
	select->collin = 0;
	ft_winsize(select);
}

void		ft_deselect_all(t_select *select)
{
	select->pos = select->elems->prev;
	select->start = select->elems;
	while (select->pos != select->elems)
	{
		select->pos->data_size &= ~1;
		select->pos = select->pos->prev;
	}
	select->pos->data_size &= ~1;
	ft_tgoto(select, 0, 0);
	select->collin = 0;
	ft_winsize(select);
}

void		ft_selectelem(t_select *select)
{
	if (!((select->pos->data_size) & 1))
		select->pos->data_size |= 1;
	else
		select->pos->data_size &= ~1;
	ft_gonextline(select);
}
