/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:32:17 by numussan          #+#    #+#             */
/*   Updated: 2022/08/24 00:03:16 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"

static void	ft_send_bin(char c, pid_t pid)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if ((c & 1) == 1)
			kill(pid, 31);
		else
			kill(pid, 30);
		c = c >> 1;
		i++;
		usleep(170);
	}
}

static int	ft_check_errors(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		return (1);
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	process_id;
	int		i;

	i = 0;
	ft_check_errors(argc, argv);
	process_id = ft_atoi(argv[1]);
	if (process_id <= 0)
		return (1);
	while (argv[2][i])
	{
		ft_send_bin(argv[2][i], process_id);
		i++;
	}
	return (0);
}
