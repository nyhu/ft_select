#include "ft_select.h"

static void	ft_listprint(t_select *select)
{
	
}

static int	ft_chrmatch(t_select *select)
{
	int				i;
	static ssize_t	match[] = {CLF, SUP, CHT, DEL, LEF, RIG, UPP, DOW,
								CLEF, CRIG, CUPP, CDOW, END, HOM, NUL};

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

	static void		(*ftab[])(t_select *) = {&ft_sup, &ft_autocomp,
		&ft_del, &ft_left, &ft_right, &ft_up, &ft_down,
		&ft_ctrlleft, &ft_ctrlright, &ft_ctrlup, &ft_ctrldown,
		&ft_goend, &ft_gohome};

	ft_clear(void);
	ft_listprint(select);
	ft_bzero(select->buf, 9);
	if (read(stream->fd, stream->buf, 8) < 0)
		ft_exit_init(select, READ_ERR);
	if (!(match = ft_chrmatch(select)))
		ft_exit_init(select, NULL);
	else if (match > 0)
		(*ftab[match - 1])(select);
	return (1);
}
