/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:19:04 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/14 13:22:56 by kyung-ki         ###   ########.fr       */
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
			usleep(100);
			lshift++;
		}
		i++;
		lshift = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	ft_printf("%d\n", getpid());
	if (argc == 3)
	{
		if (!argv[0])
			printf("No empty string\n");
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
		int bit = *(str);
		printf("char : %c  %d => ",bit, bit);
		for (int i = 0; i <8; i++)
		{
			if (bit % 2 == 0)
				printf("0");
			else
				printf("1");
			bit /= 2;
		}
		printf("\n");
*/