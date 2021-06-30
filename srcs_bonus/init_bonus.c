/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:28:56 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 10:04:00 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_pipex_b	pipex_bonus_init(size_t argc, char **envp)
{
	t_pipex_b	pb;
	size_t		i;

	i = 0;
	pb.args = (t_arg *)malloc(sizeof(t_arg) * (argc + 1));
	pb.nb_args = 0;
	pb.envp = envp;
	pb.pipes = (t_m_pipe){0};
	pb.use_here_doc = 0;
	if (!pb.args)
		return ((t_pipex_b){0, NULL, 0, {0}, 0, 0});
	while (i < argc)
	{
		pb.args[i] = (t_arg){0};
		++i;
	}
	return (pb);
}

void	free_here_doc(t_pipex_b *pb)
{
	size_t	i;

	i = 0;
	if (pb->here_doc_tab && pb->use_here_doc)
	{
		while (pb->here_doc_tab[i])
		{
			free(pb->here_doc_tab[i]);
			++i;
		}
		free(pb->here_doc_tab);
		unlink(HERE_DOC_FILE_NAME);
	}
}

void	free_pipex_bonus(t_pipex_b *pb)
{
	size_t	i;

	if (pb->args)
		free(pb->args);
	i = 0;
	if (pb->pipes.pipe_tab)
	{
		while (pb->pipes.pipe_tab[i])
		{
			ft_free_tab(pb->pipes.pipe_tab[i]);
			++i;
		}
		free(pb->pipes.pipe_tab);
	}
	if (pb->use_here_doc)
		free_here_doc(pb);
	if (pb->pipes.ac_pipes)
		free(pb->pipes.ac_pipes);
}

void	add_arg_bonus(t_pipex_b *pb, t_arg arg)
{
	pb->args[pb->nb_args] = arg;
	pb->nb_args++;
}
