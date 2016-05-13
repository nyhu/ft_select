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

void	ft_select_all(t_select *select)
{
	select->pos = select->elems->prev;
	select->start = select->elems;
	while (select->pos != select->elems)
	{
		if (!(select->pos->data_size))
			select->pos->data_size = 1;
		select->pos = select->pos->prev;
	}
	if (!(select->pos->data_size))
		select->pos->data_size = 1;
	ft_winsize(select);
}

void	ft_deselect_all(t_select *select)
{
	select->pos = select->elems->prev;
	select->start = select->elems;
	while (select->pos != select->elems)
	{
		if (select->pos->data_size)
			select->pos->data_size = 0;
		select->pos = select->pos->prev;
	}
	if (select->pos->data_size)
		select->pos->data_size = 0;
	ft_winsize(select);
}

void	ft_selectelem(t_select *select)
{
	if (!(select->pos->data_size))
		select->pos->data_size = 1;
	else
		select->pos->data_size = 0;
	ft_gonextline(select);
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
