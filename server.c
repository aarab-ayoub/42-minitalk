/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:13:45 by ayaarab           #+#    #+#             */
/*   Updated: 2025/02/02 00:37:45 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#define GREEN "\033[32m"
#define RESET "\033[0m"

void	handle_signal(int sig,siginfo_t *info, void *context)
{
	static int	bit_count = 0;
	static char	c = 0;

	(void)context;
	if(info->si_pid == 0)
	{
		ft_printf("Signal received from client: %d\n", info->si_pid);
		// kill(info->si_pid, SIGUSR1);
	}
	if (sig == SIGUSR1)
		c = c << 1 | 0;
	else if (sig == SIGUSR2)
		c = c << 1 | 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
		}
		else
		{
			write(1, &c, 1);
		}
		bit_count = 0;
		c = 0;
	}
	// kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	// signal(SIGUSR1, handle_signal);
	// signal(SIGUSR2, handle_signal);

	ft_printf(GREEN "Server PID: %d\n" RESET, getpid());

	while (1)
		pause();

	return (0);
}