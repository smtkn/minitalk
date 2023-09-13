/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:28:10 by stakan            #+#    #+#             */
/*   Updated: 2023/02/27 09:40:19 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	getbit(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 7;
		c = *str++;
		while (i >= 0)
		{
			if (c >> i & 1)
				kill(pid, 30);
			else
				kill(pid, 31);
			usleep(100);
			i--;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		getbit(ft_atoi(argv[1]), argv[2]);
		getbit(ft_atoi(argv[1]), "\n");
	}
	else
	{
		write(1, "Error: wrong format.\n", 22);
		write(1, "Try: ./client <PID> <MESSAGE>\n", 31);
	}
	return (0);
}
