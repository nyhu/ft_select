/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:38:20 by tboos             #+#    #+#             */
/*   Updated: 2016/05/11 14:38:25 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_nextcoord(t_select *select)
{
	select->pos = select->pos->next;
	if (select->collin == select->nb_elem - 1)
		select->collin = 0;
	else
	{
		(select->collin)++;
		if (select->collin > (select->maxcol * select->maxlin))
			ft_winsize(select) ;
	}
}

void	ft_goprevline(t_select *select)
{
	t_dclist	*rabbit;

	rabbit = select->pos->prev;
	while (rabbit != select->pos)
		ft_nextcoord(select);
	ft_elemprint(select, select->pos->next);
	tputs(tgoto(tgetstr("cm", NULL),
	(select->collin / select->maxlin) * select->len_max,
	select->collin % select->maxlin), 1, &ft_putcharinterr);
	ft_elemprint(select, select->pos);
	tputs(tgoto(tgetstr("cm", NULL),
	(select->collin / select->maxlin) * select->len_max,
	select->collin % select->maxlin), 1, &ft_putcharinterr);
}

void	ft_gonextline(t_select *select)
{
	ft_nextcoord(select);
	ft_elemprint(select, select->pos->prev);
	tputs(tgoto(tgetstr("cm", NULL),
	(select->collin / select->maxlin) * select->len_max,
	select->collin % select->maxlin), 1, &ft_putcharinterr);
	ft_elemprint(select, select->pos);
	tputs(tgoto(tgetstr("cm", NULL),
	(select->collin / select->maxlin) * select->len_max,
	select->collin % select->maxlin), 1, &ft_putcharinterr);
}

void	ft_gonextcol(t_select *select)
{
	t_ushort	mem;

	mem = select->collin % select->maxlin;
	ft_nextcoord(select);
	ft_elemprint(select, select->pos->prev);
	while (mem != select->collin % select->maxlin)
		ft_nextcoord(select);
	tputs(tgoto(tgetstr("cm", NULL),
	(select->collin / select->maxlin) * select->len_max,
	select->collin % select->maxlin), 1, &ft_putcharinterr);
	ft_elemprint(select, select->pos);
	tputs(tgoto(tgetstr("cm", NULL),
	(select->collin / select->maxlin) * select->len_max,
	select->collin % select->maxlin), 1, &ft_putcharinterr);
}

void	ft_goprevcol(t_select *select)
{
	t_ushort	mem;

	mem = select->collin;
	ft_nextcoord(select);
	ft_elemprint(select, select->pos->prev);
	while (mem % select->maxlin != select->collin % select->maxlin)
	{
		ft_nextcoord(select);
		if (mem % select->maxlin == select->collin % select->maxlin
			&& ((select->collin < mem && select->collin < mem - select->maxlin)
			|| (select->collin > mem
			&& select->collin < (mem + select->nb_elem - select->maxlin))))
		ft_nextcoord(select);
	}
	tputs(tgoto(tgetstr("cm", NULL),
	(select->collin / select->maxlin) * select->len_max,
	select->collin % select->maxlin), 1, &ft_putcharinterr);
	ft_elemprint(select, select->pos);
	tputs(tgoto(tgetstr("cm", NULL),
	(select->collin / select->maxlin) * select->len_max,
	select->collin % select->maxlin), 1, &ft_putcharinterr);
}
