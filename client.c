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

static int	ft_atoi(char *str)
{
	size_t				i;
	int					sign;
	unsigned long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		if (result > LLONG_MAX && sign == 1)
			return (-1);
		if (result > LLONG_MAX && sign == -1)
			return (0);
		i++;
	}
	return (sign * result);
}

void    send_bit(int pid, char bit)
{
    if (bit == '0')
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
    usleep(100);
}

void    send_message(int pid, char *message)
{
    int i;
    char c;

    while (*message)
    {
        i = 7;
        c = *message++;
        while (i >= 0)
        {
            if ((c >> i) & 1)
                send_bit(pid, '1');
            else
                send_bit(pid, '0');
            i--;
        }
    }
    i = 7;
    while (i >= 0)
    {
        send_bit(pid, '0');
        i--;
    }
}

int main(int argc, char **argv)
{
    int pid;

    if (argc != 3)
    {
        printf("Usage: %s <server_pid> <message>\n", argv[0]);
        return (1);
    }

    pid = ft_atoi(argv[1]);
    send_message(pid, argv[2]);

    return (0);
}