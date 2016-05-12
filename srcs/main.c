/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:37:30 by tboos             #+#    #+#             */
/*   Updated: 2016/05/11 14:37:53 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			ft_scmp(void *data1, void *data2)
{
	return (ft_strcmp((char *)data1, (char *)data2));
}

static void	ft_list_init(t_select *select, int ac, char **av)
{
	int			i;
	t_dclist	*new;

	if (ac == 1)
		ft_exit_init(select, NULL);
	i = 0;
	while (++i < ac)
	{
		new = NULL;
		if (select->nb_elem == MAX_ELEM)
			ft_exit_init(select, MAXE_ERR);
		if (av[i] && ft_strlen(av[i]) && ++(select->nb_elem)
			&& !(new = ft_dclstnew((void *)av[i], 0)))
			ft_exit_init(select, LIST_ERR);
		if (new && (ft_strlen(av[i]) + 1) > (select->len_max))
			select->len_max = ft_strlen(av[i]) + 1;
		if (new)
			ft_sorted_dclist_insert(&(select->elems), new, &ft_scmp);
	}
	if (!(select->elems))
		ft_exit_init(select, NULL);
	select->pos = select->elems;
}

int			main(int ac, char **av)
{
	t_select	select;

	ft_bzero(&select, sizeof(t_select));
	if (!(select.term = ft_strdup(getenv("TERM")))
		|| !tgetent(NULL, select.term))
		ft_exit_init(&select, TERM_ERR);
	ft_list_init(&select, ac, av);
	if (!ft_termios_handle(&select, 1))
		ft_exit_init(&select, CTERM_ERR);
	tputs(tgetstr("ti", NULL), 1, &ft_putcharinterr);
	tputs(tgetstr("vi", NULL), 1, &ft_putcharinterr);
	ft_signals();
	ft_winsize(&select);
	return (0);
}
