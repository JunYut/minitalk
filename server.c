#include <signal.h>
#include "libft/Libft.h"

void	receive(int sig, siginfo_t *info, void *ucontext_t);

int main(void)
{
	struct sigaction act;
	act.sa_sigaction = receive;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);

	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
}

void	receive(int sig, siginfo_t *info, void *ucontext_t)
{
	static int sum;
	static int i;

	ft_printf("Signal[%d] received: %d, %d | PID: %d\n", ++i, sig, (sig == SIGUSR1), info->si_pid);
	sum += (sig == SIGUSR1);
	ft_printf("Sum: %d\n", sum);
	kill(info->si_pid, SIGUSR1);

	(void)ucontext_t;
}
