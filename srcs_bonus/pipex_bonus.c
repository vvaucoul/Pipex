/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:51:02 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 10:05:43 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	exec_cmd_pipe_bonus(t_pipex_b *pb, char **tab)
{
	char	*cmd;

	tab[0] = ft_multijoin((char *[]){ft_access_path(tab[0], pb->envp), NULL});
	cmd = tab[0];
	execve(cmd, tab, pb->envp);
	ft_free_tab(tab);
	return (0);
}

static	int	pipe_err(int stdout_cpy, int stdin_cpy, int ret)
{
	dup2(stdout_cpy, STDOUT_FILENO);
	dup2(stdin_cpy, STDIN_FILENO);
	close(stdout_cpy);
	close(stdin_cpy);
	return (ret);
}

static	int	loop_pipes(t_pipex_b *pb)
{
	pid_t	pid;

	while (pb->pipes.pipe_tab[pb->pipes.current_pipe + 1])
	{
		pipe(pb->pipes.fd_current);
		pid = fork();
		pb->pipes.ac_pipes[pb->pipes.current_pipe].pid = pid;
		if (pid == -1)
			return (-1);
		if (!pid)
		{
			close(pb->pipes.fd_current[0]);
			dup2(pb->pipes.fd_prev, STDIN_FILENO);
			dup2(pb->pipes.fd_current[1], STDOUT_FILENO);
			exec_cmd_pipe_bonus(pb, pb->pipes.pipe_tab[pb->pipes.current_pipe]);
			exit(EXIT_FAILURE);
		}
		close(pb->pipes.fd_current[1]);
		close(pb->pipes.fd_prev);
		pb->pipes.fd_prev = pb->pipes.fd_current[0];
		++pb->pipes.current_pipe;
	}
	return (0);
}

static	int	end_pipe_status(t_pipex_b *pb)
{
	size_t	i;
	int		ret;

	i = 0;
	while (i < pb->pipes.nb_pipes)
	{
		ret = WEXITSTATUS(pb->pipes.ac_pipes[i].status);
		if (ret < 0)
			return (ret);
		++i;
	}
	return (0);
}

int	process_pipex_bonus(t_pipex_b *pb)
{
	int		stdout_cpy;
	int		stdin_cpy;

	if ((init_pipes(pb)) < 0)
		return (ft_err("Error : failed to initialize pipes", -1, 0));
	stdout_cpy = dup(STDOUT_FILENO);
	stdin_cpy = dup(STDIN_FILENO);
	if (first_pipe(pb) < 0)
		return (pipe_err(stdout_cpy, stdin_cpy, -1)
			| ft_err("Error : pipe error : ", -1, 1));
	if (loop_pipes(pb) < 0)
		return (pipe_err(stdout_cpy, stdin_cpy, -1)
			| ft_err("Error : pipe error : ", -1, 1));
	if (last_pipe(pb) < 0)
		return (pipe_err(stdout_cpy, stdin_cpy, -1)
			| ft_err("Error : pipe error : ", -1, 1));
	if ((end_pipe_status(pb)) < 0)
		return (pipe_err(stdout_cpy, stdin_cpy, -1)
			| ft_err("Error : pipe error : ", -1, 1));
	return (pipe_err(stdout_cpy, stdin_cpy, 0));
}
