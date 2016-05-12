/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:38:03 by tboos             #+#    #+#             */
/*   Updated: 2016/05/11 14:38:08 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_mvrightcol(t_select *select)
{
	int		i;

	i = select->len_max;
	while (i--)
		tputs(tgetstr("nd", NULL), 1, &ft_putcharinterr);
}

void	ft_mvuplin(t_select *select)
{
	int		i;

	i = select->maxlin;
	while (i--)
		tputs(tgetstr("up", NULL), 1, &ft_putcharinterr);
//	ft_mvrightcol(select);
}

void	ft_mvdolin(t_select *select)
{
	size_t	i;

	i = select->len_max;
	while (i--)
		tputs(tgetstr("le", NULL), 1, &ft_putcharinterr);
	tputs(tgetstr("do", NULL), 1, &ft_putcharinterr);
}
