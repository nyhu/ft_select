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

void	ft_goprevline(t_select *select)
{
	select->pos = select->pos->prev;
}

void	ft_gonextline(t_select *select)
{
	select->pos = select->pos->next;
}

void	ft_gonextcol(t_select *select)
{
	select->pos = ft_dclist_at(select->pos, select->maxlin);
}

void	ft_goprevcol(t_select *select)
{
	select->pos = ft_dclist_at(select->pos, select->nb_elem - select->maxlin);
}
