/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_specials_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:21:54 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 09:50:32 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

int	first_pipe(t_pipex_b *pb)
{
	pid_t	pid;
	char	*file;

	pipe(pb->pipes.fd_current);
	file = NULL;
	pid = fork();
	pb->pipes.ac_pipes[pb->pipes.current_pipe].pid = pid;
	if (pid == -1)
		return (-1);
	if (!pid)
	{
		close(pb->pipes.fd_current[0]);
		dup2(pb->pipes.fd_current[1], STDOUT_FILENO);
		file = ft_ternary(HERE_DOC_FILE_NAME,
				pb->args[0].data, pb->use_here_doc);
		if ((redir_in(pb, (t_arg){file})) == -1)
			return (-1);
		exit(EXIT_FAILURE);
	}
	close(pb->pipes.fd_current[1]);
	pb->pipes.fd_prev = pb->pipes.fd_current[0];
	pb->pipes.ac_pipes[pb->pipes.current_pipe].pid = pid;
	++pb->pipes.current_pipe;
	return (0);
}

static	void	end_pipes(t_pipex_b *pb)
{
	size_t	i;

	i = 0;
	while (i <= pb->pipes.nb_pipes)
	{
		waitpid(pb->pipes.ac_pipes[i].pid, &pb->pipes.ac_pipes[i].status, 0);
		++i;
	}
}

int	last_pipe(t_pipex_b *pb)
{
	pid_t	pid;

	pid = fork();
	pb->pipes.ac_pipes[pb->pipes.current_pipe].pid = pid;
	if (pid == -1)
		return (-1);
	if (!pid)
	{
		dup2(pb->pipes.fd_prev, STDIN_FILENO);
		if ((*(int *)ft_ternary((int []){1}, (int []){0}, pb->use_here_doc)))
		{
			if ((redir_double_out(pb, pb->args[pb->nb_args - 1])) == -1)
				return (-1);
		}
		else
		{
			if ((redir_out(pb, pb->args[pb->nb_args - 1])) == -1)
				return (-1);
		}
		exit(EXIT_FAILURE);
	}
	close(pb->pipes.fd_current[0]);
	end_pipes(pb);
	return (0);
}
