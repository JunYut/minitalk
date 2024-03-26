#include <signal.h>
#include "libft/Libft.h"

int	g_boolean = 1;

void	send_message(int pid, char *message);
void	send_char(int pid, char c);
void	receive(int sig, siginfo_t *info, void *ucontext);

int	main(int argc, char *argv[])
{
	ft_printf("Client PID: %d\n", getpid());

	struct sigaction	action1;
	action1.sa_sigaction = receive;
	action1.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action1, NULL);

	send_message(ft_atoi(argv[1]), argv[2]);

	ft_printf("Client exit\n");

	(void)argc;
	(void)argv;
}

void	send_message(int pid, char *message)
{
	while (*message)
	{
		send_char(pid, *message);
		message++;
	}
}

void	send_char(int pid, char c)
{
	int i = -1;
	while (++i < 8)
	{
		ft_printf("Sending bit[%d] %d\n", i + 1, (c >> i) & 1);
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
	}
}

void	receive(int sig, siginfo_t *info, void *ucontext)
{
	static int i;
	g_boolean = 0;
	ft_printf("Signal[%d] received: %d | PID: %d\n", ++i, sig, info->si_pid);
	(void)sig;
	(void)info;
	(void)ucontext;
}
