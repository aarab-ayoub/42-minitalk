/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:13:42 by ayaarab           #+#    #+#             */
/*   Updated: 2025/02/02 11:56:57 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <stdlib.h>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

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
			usleep(100);
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
    int pid;

    if (argc != 3)
    {
        printf(RED "❌ Usage: %s <server_pid> <message>\n" RESET, argv[0]);
        return (1);
    }
    else
    {
        pid = ft_atoi(argv[1]);
        if (pid <= 0)
        {
            printf(RED "❌ Invalid PID: %s\n" RESET, argv[1]);
            return (1);
        }
        printf(GREEN "✅ Sending message to PID %d...\n" RESET, pid);
        send_message(pid, argv[2]);
        printf(GREEN "✅ Message sent successfully! 🎉\n" RESET);
    }
    return (0);
}
