/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-biha <fle-biha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:40:51 by fle-biha          #+#    #+#             */
/*   Updated: 2021/06/04 10:33:17 by fle-biha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

void	ft_aff_pid(pid_t pid)
{
	ft_putstr_fd("PID = ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_signal_handler(int sig)
{
	static char	letter[9];
	static int	i = 0;

	if (sig == SIGUSR1)
	{
		letter[i] = '1';
		i++;
	}
	if (sig == SIGUSR2)
	{
		letter[i] = '0';
		i++;
	}
	if (i == 8)
	{
		letter[i] = '\0';
		ft_putchar_fd(ft_atoi_base(letter, 2), 1);
		i = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_aff_pid(pid);
	signal(SIGUSR1, ft_signal_handler);
	signal(SIGUSR2, ft_signal_handler);
	while (1)
	{
		pause();
	}
}
