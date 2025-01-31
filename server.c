/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:13:45 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/31 14:59:21 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig)
{
	static int	bit_count = 0;
	static char	c = 0;

	if (sig == SIGUSR1)
		c = c << 1 | 0;
	else if (sig == SIGUSR2)
		c = c << 1 | 1;
	bit_count++;
	if (bit_count == 8)
	{
		
		write(1, &c, 1);
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction sa;

	sa.sa_handler = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	// signal(SIGUSR1, handle_signal);
	// signal(SIGUSR2, handle_signal);

	printf("Server PID: %d\n", getpid());

	while (1)
		pause();

	return (0);
}