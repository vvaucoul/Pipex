/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:34:41 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 09:06:26 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	pipex_init(size_t argc, char **envp)
{
	t_pipex	p;
	size_t	i;

	i = 0;
	p.args = (t_arg *)malloc(sizeof(t_arg) * (argc + 1));
	p.nb_args = 0;
	p.envp = envp;
	if (!p.args)
		return ((t_pipex){0, NULL, 0, {0}});
	while (i < argc)
	{
		p.args[i] = (t_arg){0};
		++i;
	}
	return (p);
}

void	free_pipex(t_pipex *p)
{
	free(p->args);
}

/*
** 	LINKED LIST
*/

t_arg	create_arg(void *data)
{
	t_arg	new;

	new.data = data;
	return (new);
}

void	add_arg(t_pipex *p, t_arg arg)
{
	p->args[p->nb_args] = arg;
	p->nb_args++;
}
