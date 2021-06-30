/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:35:44 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 09:12:42 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	int	check_existing(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	return (1);
}

static	int	check_access(t_pipex *p, int i)
{
	char	**tmp;
	char	*path;

	tmp = ft_split(p->args[i].data, ' ');
	path = ft_access_path(tmp[0], p->envp);
	if (!path)
	{
		ft_free_tab(tmp);
		if (path)
			free(path);
		return (-1);
	}
	ft_free_tab(tmp);
	free(path);
	return (0);
}

int	parsing(t_pipex *p, size_t argc, char **argv)
{
	size_t	i;

	i = 1;
	while (i < argc)
	{
		add_arg(p, create_arg((void *)argv[i]));
		++i;
	}
	if ((check_access(p, 1)) < 0)
		return (ft_err("Error : cmd invalid", -1, 0));
	if ((check_access(p, 2)) < 0)
		return (ft_err("Error : cmd1 invalid", -1, 0));
	if (!(check_existing(p->args[0].data)))
		return (ft_err("Error : infile invalid", -1, 0));
	return (0);
}
