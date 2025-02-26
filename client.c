/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:13:42 by ayaarab           #+#    #+#             */
/*   Updated: 2025/02/02 15:35:33 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, char bit)
{
	if (bit == '0')
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
}

void	send_message(int pid, char *message)
{
	int	i;
	int	bit;

	i = 0;
	while (message[i])
	{
		bit = 7;
		while (bit >= 0)
		{
			if (message[i] & (1 << bit))
				send_bit(pid, '1');
			else
				send_bit(pid, '0');
			usleep(500);
			bit--;
		}
		i++;
	}
	bit = 7;
	while (bit >= 0)
	{
		send_bit(pid, '0');
		bit--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf(RED "❌ Usage: %s <server_pid> <message>\n" RESET, argv[0]);
		return (1);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			ft_printf(RED "❌ Invalid PID: %s\n" RESET, argv[1]);
			return (1);
		}
		ft_printf(GREEN "✅ Sending message to PID %d...\n" RESET, pid);
		send_message(pid, argv[2]);
		ft_printf(GREEN "✅ Message sent successfully!\n" RESET);
	}
	return (0);
}
