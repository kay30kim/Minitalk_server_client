/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:46:49 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/14 14:40:22 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, char *str)
{
	int	lshift;
	int	i;

	i = 0;
	while (str[i])
	{
		lshift = 0;
		while (lshift < 8)
		{
			if (str[i] << lshift & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
			lshift++;
		}
		i++;
		lshift = 0;
	}
}

void	handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Singal sending back accept\n");
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	sig;

	i = 0;
	if (argc == 3)
	{
		if (!argv[0])
			printf("No empty string\n");
		sig.sa_handler = &handler;
		sig.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pid = ft_atoi(argv[1]);
		send_message(pid, argv[2]);
		send_message(pid, "\n");
	}
	else
	{
		ft_printf("Arguments need to be 3\n");
	}
	return (0);
}
	/*
	static int				i = 0;
	static unsigned char	c = 0;

	if (signal == SIGUSR2)
		c = c << 1;
	else if (signal == SIGUSR1)
		c = (c << 1) | 0b00000001;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
	*/
