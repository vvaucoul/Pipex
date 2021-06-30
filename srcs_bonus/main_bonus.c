/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:54:32 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 10:04:14 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	execute(t_pipex_b *pb, int argc, char **argv)
{
	if ((parsing_bonus(pb, argc, argv)) < 0)
	{
		free_pipex_bonus(pb);
		return (-1);
	}
	if (pb->use_here_doc)
	{
		if ((process_here_doc(pb) < 0))
		{
			free_pipex_bonus(pb);
			return (-1);
		}
	}
	if ((process_pipex_bonus(pb)) < 0)
	{
		free_pipex_bonus(pb);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex_b	pb;

	if (argc < 5)
	{
		return (ft_err("Bad arguments,\tusage [1] :\t	\r\t\t\
		./pipex file1 cmd1 cmd2 cmdn file2\n\t\t \r\
		usage [2] :\t./pipex here_doc LIMITER cmd cmd2 file", -1, 0));
	}
	else
	{
		pb = pipex_bonus_init(argc, envp);
		if (!pb.args)
			return (ft_err("Error : failed to initialize pipex", -1, 0));
		if ((execute(&pb, argc, argv)) < 0)
			return (-1);
		free_pipex_bonus(&pb);
	}
	return (0);
}
