#include <signal.h>
#include "libft/Libft.h"

void	receive(int sig, siginfo_t *info, void *ucontext_t);

int main(int argc, char *argv[])
{
	struct sigaction act;
	act.sa_sigaction = receive;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);

	int i = -1;
	while (++i < 100000)
	{
		if (i & 1)
			kill(ft_atoi(argv[1]), SIGUSR1);
		else
			kill(ft_atoi(argv[1]), SIGUSR2);
		pause();
	}
	ft_printf("All signals sent\n");

	(void)argc;
	return (0);
}

void	receive(int sig, siginfo_t *info, void *ucontext_t)
{
	static int i;

	ft_printf("Signal[%d] received: %d | PID: %d\n", ++i, sig, info->si_pid);
	(void)ucontext_t;
}
