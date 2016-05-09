#include "ft_select.h"

void	ft_freedata(void *data, size_t size)
{
	size = 0;
	data = NULL;
}

void	ft_exit_init(t_select *select, char *err)
{
	ft_termios_handle(select, 0);
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
