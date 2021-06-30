/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_pipes_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:17:57 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 09:49:40 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

int	redir_in(t_pipex_b *pb, t_arg infile)
{
	int	fd;

	fd = open(infile.data, O_RDONLY);
	if (fd < 0)
		exit(2);
	if ((dup2(fd, 0)) == -1)
		exit(EXIT_FAILURE);
	exec_cmd_pipe_bonus(pb, pb->pipes.pipe_tab[pb->pipes.current_pipe]);
	close(fd);
	exit(EXIT_SUCCESS);
}

int	redir_out(t_pipex_b *pb, t_arg outfile)
{
	int	fd;

	fd = open(outfile.data, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		exit(2);
	if ((dup2(fd, 1)) == -1)
		exit(EXIT_FAILURE);
	exec_cmd_pipe_bonus(pb, pb->pipes.pipe_tab[pb->pipes.current_pipe]);
	close(fd);
	exit(EXIT_SUCCESS);
}

int	redir_double_out(t_pipex_b *pb, t_arg outfile)
{
	int	fd;

	fd = open(outfile.data, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		exit(2);
	if ((dup2(fd, 1)) == -1)
		exit(EXIT_FAILURE);
	exec_cmd_pipe_bonus(pb, pb->pipes.pipe_tab[pb->pipes.current_pipe]);
	close(fd);
	exit(EXIT_SUCCESS);
}
