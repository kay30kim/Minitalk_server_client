/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:19:04 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/13 22:44:12 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendMessage(int pid, char *str)
{
	int	lshift;
	int	c;

	lshift = 0;
	while (*str)
	{
		c = *(str);
		while (lshift < 8)
		{
			if (c << lshift & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			lshift++;
		}
		str++;
		lshift = 0;
	}
}

int	main(int argc, char **argv){
	int	pid;
	int	i;

	i = 0;
	ft_printf("%d\n", getpid());
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		sendMessage(pid, argv[2]);
	}
	else
	{
		ft_printf("Arguments need to be 3\n");
	}
	return (0);
}