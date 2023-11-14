/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:47:18 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/14 13:45:34 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	listen_handler(int sig, siginfo_t *info, void *content)
{
	static int				i = 0;
	static unsigned char	c = 0;

	(void)content;
	if (sig == SIGUSR2)
	{
		c = c << 1;
		if (kill(info->si_pid, SIGUSR2) == -1)
			exit(EXIT_FAILURE);
	}
	else if (sig == SIGUSR1)
	{
		c = (c << 1) | 0b00000001;
		if (kill(info->si_pid, SIGUSR1) == -1)
			exit(EXIT_FAILURE);
	}
	usleep(100);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("PID : %d\n", getpid());
	while (1)
	{
		sig.sa_sigaction = &listen_handler;
		sig.sa_flags = SA_SIGINFO;
		if (sigaction(SIGUSR1, &sig, NULL) == -1)
			ft_putstr_fd("SIGUSR1 error\n", 2);
		if (sigaction(SIGUSR2, &sig, NULL) == -1)
			ft_putstr_fd("SIGUSR2 error\n", 2);
	}
	return (0);
}
