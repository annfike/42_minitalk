/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <adelaloy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:29:28 by adelaloy          #+#    #+#             */
/*   Updated: 2023/11/13 16:48:42 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dst = malloc(sizeof(char) * i + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*make_string(char *s, char ch)
{
	char	*new;
	int		i;

	i = 0;
	while (s[i])
		i++;
	new = malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = ch;
	new[i + 1] = '\0';
	free(s);
	return (new);
}

void	signal_handler(int signum)
{
	static int	bit;
	static char	ch;
	static char	*s;

	if (!s)
		s = ft_strdup("");
	if (signum == SIGUSR1)
	{
		ch += 1 << (7 - bit);
	}
	bit++;
	if (bit == 8)
	{
		s = make_string(s, ch);
		if (ch == '\0')
		{
			ft_putstr_fd(s, 1);
			ft_putstr_fd("\n", 1);
			free(s);
			s = NULL;
		}
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
	printf("Hello, my PID is: %d, waiting for your message..\n", pid);
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

/*leaks --atExit -- ./a.out
leaks server  (when its running)
valgrind ./a.out*/

/*
./client 30264 "$(cat /dev/urandom | head -c 10)"
./client 30264 "$(cat /dev/urandom | head -c 9999)"
./client 30264 "$(cat /dev/urandom | head -c 9999999)"
*/
