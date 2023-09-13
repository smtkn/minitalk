/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakan <stakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:28:24 by stakan            #+#    #+#             */
/*   Updated: 2023/02/14 10:28:26 by stakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	len(int a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a / 10;
	}
	return (i);
}

char	*ft_itoa(int a)
{
	int		i;
	char	*str;

	i = len(a);
	str = (char *)malloc(sizeof(char) * i + 1);
	str[i] = '\0';
	while (a)
	{
		str[i - 1] = '0' + (a % 10);
		a = a / 10;
		i--;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int	d;
	int	s;

	d = 1;
	s = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
			str++;
	if (*str == '-')
	{
		d = d * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (*str == '-' || *str == '+')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		s = (s * 10);
		s = s + (*str - '0');
		str++;
	}
	return (s * d);
}
