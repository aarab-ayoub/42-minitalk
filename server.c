/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:13:45 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/29 17:35:19 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handel_signals(int signum)
{
	if (signum == SIGUSR1)
		write(1, "Recieve SIGUSR1", 15);
	else if (signum == SIGUSR2)
		write(1, "Recieve SIGUSR2", 15);
}

int	server_main(void)
{
	// struct s
	
	// while (1)
	// {
	// 	printf("this my PID %d\n", getpid());
	// 	usleep(6 * 1000 * 1000);
	// }
}