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

static void	ft_elemprint(t_select *select, t_dclist *rabbit)
{
	if (rabbit == select->pos)
		tputs(tgetstr("us", NULL), 1, &ft_putcharinterr);
	if (rabbit->data_size)
		tputs(tgetstr("mr", NULL), 1, &ft_putcharinterr);
	ft_putstrpad_fd(((char *)rabbit->data), (int)select->len_max, 'L', FD);
	tputs(tgetstr("me", NULL), 1, &ft_putcharinterr);
}

static void	ft_listprint(t_select *select)
{
	t_dclist		*rabbit;
	t_ushort		col;
	t_ushort		lin;

	col = 0;
	lin = 0;
	ft_elemprint(select, select->elems);
	rabbit = select->elems->next;
	while (rabbit != select->elems)
	{
		lin++;
		if (lin > select->maxlin)
		{
			lin = 0;
			col++;
			if (col > select->maxcol)
				break ;
			ft_mvuplin(select);
		}
		else
			ft_mvdolin(select);
		ft_elemprint(select, rabbit);
		rabbit = rabbit->next;
	}
}

static int	ft_chrmatch(t_select *select)
{
	int				i;
	static ssize_t	match[] = {CLF, SUP, DEL, LEF, RIG, UPP, DOW,
								END, HOM, NUL};

	i = 0;
//printf("\nbuf   = %lx\n", ((ssize_t *)(select->buf))[0]);
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
		&ft_goendelem, &ft_gohomeelem};

	ft_clear();
	ft_listprint(select);
	ft_bzero(select->buf, 9);
	if (read(0, select->buf, 8) < 0)
		ft_exit_init(select, READ_ERR);
	if (!(match = ft_chrmatch(select)))
		ft_exit_init(select, NULL);
	else if (match > 0)
		(*ftab[match - 1])(select);
	return (1);
}
