/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaarab <ayaarab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:13:42 by ayaarab           #+#    #+#             */
/*   Updated: 2025/01/29 17:30:33 by ayaarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


int client_main(int argc, char **argv)
{
	if (argc != 4)
	{
		printf("Usage:./client <pid> <message>\n");
	}
	else
	{
		int pid = ft_atoi(argv[1]);
		char *message = argv[2];
		int i = 0;
		while (message[i])
		{
			int j = 0;
			while (j < 8)
			{
				if (message[i] & (1 << j))
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				usleep(100);
				j++;
			}
			i++;
		}
	}
	return 0;
}