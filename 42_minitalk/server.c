/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:29:28 by adelaloy          #+#    #+#             */
/*   Updated: 2023/11/13 14:51:15 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 10)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	signal_handler(int signum)
{
	static int	bit;
	static int	ch;

	if (signum == SIGUSR1)
	{
		ch += 1 << (7 - bit);
	}
	bit++;
	if (bit == 8)
	{
		write(1, &ch, 1);
		bit = 0;
		ch = 0;
	}
}

int	main(int argn, char **args)
{
	pid_t				pid;
	struct sigaction	action;

	(void)argn;
	(void)args;
	pid = getpid();
	write(1, "Hello!\nMy PID: ", 15);
	ft_putnbr(pid);
	write(1, "\n", 1);
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
