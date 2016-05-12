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
	select->pos = select->elems;
}

void	ft_goendelem(t_select *select)
{
	select->pos = select->elems->prev;
}
