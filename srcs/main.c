/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:27:06 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 09:15:45 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;

	if (argc != 5)
	{
		return (ft_err("Bad arguments, usage : ./pipex infile cmd1 cmd2 outfile"
				, -1, 0));
	}
	else
	{
		p = pipex_init(argc, envp);
		if (!p.args)
			return (ft_err("Error : failed to initialize pipex", -1, 0));
		if ((parsing(&p, argc, argv)) < 0)
		{
			free_pipex(&p);
			return (-1);
		}
		process_pipex(&p);
		free_pipex(&p);
	}
	return (0);
}
