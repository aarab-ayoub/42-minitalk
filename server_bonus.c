/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:13:45 by ayaarab           #+#    #+#             */
/*   Updated: 2025/02/02 16:18:31 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	process_character(char c, int pid)
{
	if (c == '\0')
	{
		write(1, "\n", 1);
		kill(pid, SIGUSR1);
	}
	else
	{
		write(1, &c, 1);
	}
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int	bit_count = 0;
	static char	c = 0;
	static int	pid;

	if (pid != info->si_pid)
	{
		bit_count = 0;
		c = 0;
	}
	pid = info->si_pid;
	(void)context;
	if (sig == SIGUSR1)
		c = c << 1 | 0;
	else if (sig == SIGUSR2)
		c = c << 1 | 1;
	bit_count++;
	if (bit_count == 8)
	{
		process_character(c, pid);
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf(GREEN "Server PID: %d\n" RESET, getpid());
	while (1)
		pause();
	return (0);
}
