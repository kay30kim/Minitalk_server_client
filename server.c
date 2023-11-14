/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:18:33 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/13 22:30:18 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	listen_handler(int sig)
{
	static int				i = 0;
	static unsigned char	c = 0;

	if (sig == SIGUSR2)
		c = c << 1;
	else if (sig == SIGUSR1)
		c = (c << 1) | 0b00000001;
	i++;
	if (i == 8)
	{
		ft_printf("%c",c);
		i = 0;
		c = 0;
	}
}

int	main()
{
	ft_printf("PID : %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, listen_handler);
		signal(SIGUSR2, listen_handler);
	}
	return (0);
}