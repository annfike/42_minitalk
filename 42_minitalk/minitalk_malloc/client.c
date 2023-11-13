/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:29:38 by adelaloy          #+#    #+#             */
/*   Updated: 2023/11/13 14:18:53 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	n;

	i = 0;
	minus = 1;
	n = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		minus = -1;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * minus);
}

void	send_bit(int pid, char ch)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		bit = (ch >> (7 - i)) & 1;
		if (bit == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		usleep(200);
	}
}

void	send_msg(int pid, const char *s)
{
	int	ch;

	while (*s)
	{
		ch = *s++;
		send_bit(pid, ch);
	}
	send_bit(pid, '\0');
}

int	main(int argc, char *argv[])
{
	int	pid;

	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		printf("Usage: ./client [pid] [message]\n");
		return (0);
	}
	send_msg(pid, argv[2]);
	return (0);
}
