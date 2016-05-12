/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:43:44 by tboos             #+#    #+#             */
/*   Updated: 2016/05/11 14:43:46 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_freedata(void *data, size_t size)
{
	(void)size;
	(void)data;
}

void	ft_resultprint(t_dclist *elems)
{
	if (elems->data_size)
	{
		ft_putstr(((char *)elems->data));
		ft_putchar(' ');
	}
}

void	ft_clear(void)
{
	tputs(tgetstr("cl", NULL), 1, &ft_putcharinterr);
}

void	ft_exit_init(t_select *select, char *err)
{
	ft_termios_handle(select, 0);
	tputs(tgetstr("ve", NULL), 1, ft_putcharinterr);
	tputs(tgetstr("te", NULL), 1, ft_putcharinterr);
	if (!err && select->elems)
		ft_dclstiter(select->elems, &ft_resultprint);
	if (err)
		FT_PUTSTRFD("ft_select: init error: ", err, "\n", 2);
	if (select->term)
		free(select->term);
	if (select->elems)
		ft_dclstdel(&(select->elems), &ft_freedata);
	if (err)
		exit(1);
	exit(0);
}
