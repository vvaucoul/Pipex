/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 09:43:52 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 09:51:53 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

static int	assign_pipe_tab(t_arg *args, size_t nb_args,
char ***pipe_tab, int use_here_doc)
{
	size_t	i;
	size_t	s_i;

	i = 0;
	s_i = *(int *)ft_ternary((int []){2}, (int []){1}, use_here_doc);
	while (i < (nb_args - 2 - use_here_doc))
	{
		pipe_tab[i] = ft_split(args[s_i].data, ' ');
		if (!pipe_tab[i])
			return (-1);
		++i;
		++s_i;
	}
	return (0);
}

static char	***init_pipe_tab(t_pipex_b *pb)
{
	char	***pipe_tab;
	int		ret;

	pipe_tab = (char ***)ft_memalloc(sizeof(char **),
			ft_args_size(pb->args, pb->nb_args) * MAX_CHAR_PROMPT);
	if (!pipe_tab)
		return (NULL);
	ret = assign_pipe_tab(pb->args, pb->nb_args, pipe_tab, pb->use_here_doc);
	if (ret < 0)
		return (NULL);
	return (pipe_tab);
}

int	init_pipes(t_pipex_b *pb)
{
	size_t	i;

	i = 0;
	pb->pipes.pipe_valid = 0;
	pb->pipes.nb_pipes = pb->nb_args - 2 - pb->use_here_doc;
	pb->pipes.pipe_tab = init_pipe_tab(pb);
	if (!pb->pipes.pipe_tab)
		return (-1);
	pb->pipes.current_pipe = 0;
	pb->pipes.fd_prev = 0;
	pb->pipes.pipe_valid = 1;
	pb->pipes.ac_pipes = (t_cpipe *)malloc(sizeof(t_cpipe) * pb->nb_args + 1);
	if (!pb->pipes.ac_pipes)
		return (-1);
	while (i < pb->nb_args)
	{
		pb->pipes.ac_pipes[i] = (t_cpipe){0, 0};
		++i;
	}
	return (0);
}

/*
**
**	printf("\n\n#########################\n");
**	printf("\t- Pipes Tab = \n");
**	for (size_t i = 0; i < pb->pipes.nb_pipes; i++) {
**		printf("PipeTab [%ld] = \n", i);
**		ft_print_tab(pb->pipes.pipe_tab[i]);
**	}
**	printf("#########################\n\n\n");
**
*/
