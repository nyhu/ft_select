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
	if (rabbit->data_size & 1)
		tputs(tgetstr("mr", NULL), 1, &ft_putcharinterr);
	if (S_ISDIR(rabbit->data_size))
		ft_putstr_fd(ANSI_COLOR_CYAN, FD);
	else if (S_ISLNK(rabbit->data_size))
		ft_putstr_fd(ANSI_COLOR_YELLOW, FD);
	else if (S_ISREG(rabbit->data_size)
		&& 00100 & rabbit->data_size)
		ft_putstr_fd(ANSI_COLOR_GREEN, FD);
	else if (S_ISCHR(rabbit->data_size))
		ft_putstr_fd(ANSI_COLOR_BLUE, FD);
	else if (S_ISBLK(rabbit->data_size))
		ft_putstr_fd(ANSI_COLOR_RED, FD);
	else if (S_ISFIFO(rabbit->data_size))
		ft_putstr_fd(ANSI_COLOR_MAGENTA, FD);
	else if (S_ISSOCK(rabbit->data_size))
		ft_putstr_fd(ANSI_COLOR_MAGENTA, FD);
	ft_putstrpad_fd(((char *)rabbit->data), (int)select->len_max, 'L', FD);
	tputs(tgetstr("me", NULL), 1, &ft_putcharinterr);
}

void		ft_listprint(t_select *select)
{
	t_dclist		*rabbit;
	t_ushort		memo;

	memo = select->collin;
	select->collin = 0;
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, &ft_putcharinterr);
	ft_elemprint(select, select->start);
	rabbit = select->start->next;
	while (rabbit != select->elems)
	{
		(select->collin)++;
			if (select->collin == (select->maxcol * select->maxlin))
				break ;
		tputs(tgoto(tgetstr("cm", NULL),
		(select->collin / select->maxlin) * select->len_max,
		select->collin % select->maxlin), 1, &ft_putcharinterr);
		ft_elemprint(select, rabbit);
		rabbit = rabbit->next;
	}
	select->collin = memo;
	tputs(tgoto(tgetstr("cm", NULL),
	(select->collin / select->maxlin) * select->len_max,
	select->collin % select->maxlin), 1, &ft_putcharinterr);
}

static int	ft_chrmatch(t_select *select)
{
	int				i;
	static ssize_t	match[] = {CLF, SUP, DEL, LEF, RIG, UPP, DOW,
					SPA, ESC, CTA, CTD, END, HOM, CTH, NUL};

	i = 0;
//dprintf(1, "\nbuf   = %lx\n", ((ssize_t *)(select->buf))[0]);
	while (match[i])
	{
//printf("\nmatch = %lx\n", match[i]);
		if (((ssize_t *)(select->buf))[0] == match[i])
			return (i);
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
		&ft_selectelem, &ft_escape_select, &ft_select_all, &ft_deselect_all,
		&ft_goendelem, &ft_gohomeelem, &ft_help};

	ft_bzero(select->buf, 9);
	if (read(0, select->buf, 8) < 0)
		ft_exit_init(select, READ_ERR);
	if (!(match = ft_chrmatch(select)))
		ft_exit_init(select, NULL);
	else if (select->maxcol && match > 0)
		(*ftab[match - 1])(select);
	return (1);
}
