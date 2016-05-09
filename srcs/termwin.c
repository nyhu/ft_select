#include "ft_select.h"

void	ft_winrec(t_stream *stream)
{
	struct winsizew;

	ioctl(stream->fd, TIOCGWINSZ, &w);
	stream->col = w.ws_col;
}

int			ft_termios_handle(t_select *select, int mode)
{
	t_termios	shell;
	static char	state = 'n';

	if (mode && state == 'n')
	{
		if (tcgetattr(STDIN_FILENO, &(select->termios_backup)) == -1
		|| !ft_memcpy(&shell, &(select->termios_backup), sizeof(t_termios)))
			return (0);
		shell.c_lflag &= ~(ICANON | ECHO);
		shell.c_cc[VMIN] = 1;
		shell.c_cc[VTIME] = 0;
		if (tcsetattr(STDIN_FILENO, TCSADRAIN, &shell) == -1)
			return (0);
		state = 'y';
	}
	else if (state == 'y')
	{
		tcsetattr(STDIN_FILENO, TCSANOW, &(select->termios_backup));
		state = 'n';
	}
	return (1);
}
