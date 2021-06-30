/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:48:26 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/21 16:04:04 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	int	exec_pipe(t_pipex *p, t_arg arg)
{
	char	**tab;
	char	*cmd;

	tab = ft_split(arg.data, ' ');
	tab[0] = ft_multijoin((char *[]){ft_access_path(tab[0], p->envp), NULL});
	cmd = tab[0];
	execve(cmd, tab, p->envp);
	ft_free_tab(tab);
	exit(EXIT_SUCCESS);
	return (0);
}

static	int	process_pipe_01(t_pipex *p, t_arg arg, t_arg infile)
{
	int	fd;

	fd = open(infile.data, O_RDONLY);
	if (fd < 0)
		exit(2);
	if ((dup2(p->pipe_fd[1], 1)) == -1)
		exit(EXIT_FAILURE);
	if ((dup2(fd, 0)) == -1)
		exit(EXIT_FAILURE);
	close(p->pipe_fd[0]);
	close(fd);
	exec_pipe(p, arg);
	exit(EXIT_FAILURE);
}

static	int	process_pipe_02(t_pipex *p, t_arg arg, t_arg outfile)
{
	int	fd;

	fd = open(outfile.data, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		exit(2);
	if ((dup2(p->pipe_fd[0], 0)) == -1)
		exit(EXIT_FAILURE);
	if ((dup2(fd, 1)) == -1)
		exit(EXIT_FAILURE);
	close(p->pipe_fd[1]);
	close(fd);
	exec_pipe(p, arg);
	exit(EXIT_FAILURE);
	return (0);
}

static	int	do_pipe(t_pipex *p)
{
	pid_t	pid;
	int		st;

	if ((pipe(p->pipe_fd)) < 0)
		return (ft_putstrerrno(-1));
	pid = fork();
	if (pid == -1)
		return (ft_putstrerrno(-1));
	else if (!pid)
		process_pipe_02(p, p->args[2], p->args[3]);
	else
		process_pipe_01(p, p->args[1], p->args[0]);
	waitpid(-1, &st, 0);
	return (WEXITSTATUS(st));
}

int	process_pipex(t_pipex *p)
{
	int		save_stdin;
	int		save_stdout;
	int		ret;

	ret = 0;
	save_stdin = dup(STDIN_FILENO);
	save_stdout = dup(STDOUT_FILENO);
	ret = (do_pipe(p));
	dup2(save_stdin, STDIN_FILENO);
	dup2(save_stdout, STDOUT_FILENO);
	close(save_stdin);
	close(save_stdout);
	if (ret == EXIT_FAILURE || ret == 2)
		return (ft_putstrerrno(-1));
	return (ret);
}
