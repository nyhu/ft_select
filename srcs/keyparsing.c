/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyparsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:41:03 by tboos             #+#    #+#             */
/*   Updated: 2016/05/11 14:41:43 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_elemprint(t_select *select, t_dclist *rabbit)
{
	if (rabbit == select->pos)
		tputs(tgetstr("us", NULL), 1, &ft_putcharinterr);
	if (rabbit->data_size)
		tputs(tgetstr("mr", NULL), 1, &ft_putcharinterr);
	ft_putstrpad_fd(((char *)rabbit->data), (int)select->len_max, 'L', FD);
	tputs(tgetstr("me", NULL), 1, &ft_putcharinterr);
}

void		ft_listprint(t_select *select)
{
	t_dclist		*rabbit;

	select->collin = 0;
	ft_elemprint(select, select->start);
	rabbit = select->start->next;
	while (rabbit != select->elems)
	{
		(select->collin)++;
			if (select->collin > (select->maxcol * select->maxlin))
				break ;
		tputs(tgoto(tgetstr("cm", NULL),
		(select->collin / select->maxlin) * select->len_max,
		select->collin % select->maxlin), 1, &ft_putcharinterr);
		ft_elemprint(select, rabbit);
		rabbit = rabbit->next;
	}
}

static int	ft_chrmatch(t_select *select)
{
	int				i;
	static ssize_t	match[] = {CLF, SUP, DEL, LEF, RIG, UPP, DOW,
					SPA, ESC, CTA, CTD, END, HOM, NUL};

	i = 0;
//dprintf(1, "\nbuf   = %lx\n", ((ssize_t *)(select->buf))[0]);
	while (match[i])
	{
//printf("\nmatch = %lx\n", ma		tch[i]);
		if (((ssize_t *)(select->buf))[0] == match[i])
			return (i)					;
		i++;
	}
	if (ft_isprint(select->buf[0]))
		return (-1);
	return (-2);
}

int			ft_keyparse(t_select *select)
{
	int				match;
	static void		(*ftab[])(t_select *) = {&ft_delelem, &ft_delelem,
		&ft_goprevcol, &ft_gonextcol, &ft_goprevline, &ft_gonextline,
		&ft_selectelem, &ft_escape_select, &ft_select_all, &ft_deselect_all, &ft_goendelem, &ft_gohomeelem};

	ft_bzero(select->buf, 9);
	if (read(0, select->buf, 8) < 0)
		ft_exit_init(select, READ_ERR);
	if (!(match = ft_chrmatch(select)))
		ft_exit_init(select, NULL);
	else if (match > 0)
		(*ftab[match - 1])(select);
	return (1);
}
