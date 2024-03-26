#include <signal.h>
#include "libft/Libft.h"

int boolean = 1;

void	receive(int sig, siginfo_t *info, void *ucontext_t);

int	main(int argc, char *argv[])
{
	ft_printf("Client PID: %d\n", getpid());

	struct sigaction	action1;
	action1.sa_sigaction = receive;
	action1.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action1, NULL);

	// Send the first signal
	kill(ft_atoi(argv[1]), SIGUSR1);

	// Wait for acknowledgments
	while (boolean)
	{
		pause();
	}

	ft_printf("Client exit\n");

	(void)argc;
	(void)argv;
}

void	receive(int sig, siginfo_t *info, void *ucontext)
{
	static int i;

	if (++i <= 1000000) {
		// Send the next signal
		kill(info->si_pid, SIGUSR1);
		ft_printf("Signal[%d] received: %d | Server PID: %d\n", i, sig, info->si_pid);
		return;
	}
	// ft_printf("PID: %d\n", getpid());
	boolean = 0;

	(void)ucontext;
}
