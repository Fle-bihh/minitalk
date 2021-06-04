/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-biha <fle-biha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:06:09 by fle-biha          #+#    #+#             */
/*   Updated: 2021/06/04 12:28:58 by fle-biha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

void	ft_verif(char *pid)
{
	while (*pid)
	{
		if (!(ft_isdigit(*pid)))
		{
			ft_putstr_fd("Please write : \"./client PID string\"\n", 1);
			exit(0);
		}
		pid++;
	}
}

void	ft_kill_error(char *binary)
{
	ft_putstr_fd("Bad PID.\n", 1);
	free(binary);
	exit(0);
}

void	ft_kill_binary(char *binary, int pid)
{
	int	i2;

	i2 = -1;
	while (binary[++i2])
	{
		if (binary[i2] == '1')
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_kill_error(binary);
			usleep(1000);
		}
		if (binary[i2] == '0')
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_kill_error(binary);
			usleep(1000);
		}
	}
}

void	ft_send_signals(pid_t pid, char *str)
{
	char	*binary;
	int		i;

	i = -1;
	while (str[++i])
	{
		binary = ft_itoa_base((unsigned char) str[i], "01");
		while (ft_strlen(binary) < 8)
			binary = ft_strjoin("0", binary, 0, 1);
		ft_kill_binary(binary, pid);
		free(binary);
	}
}

int	main(int ac, char **av)
{
	char	*s;

	if (ac != 3)
	{
		ft_putstr_fd("Please write : \"./client PID string_to_send\"\n", 1);
		exit(0);
	}
	s = ft_strjoin(av[2], "\n", 0, 0);
	ft_verif(av[1]);
	ft_send_signals(ft_atoi(av[1]), s);
	ft_putstr_fd("Data sent and received.\n", 1);
}
