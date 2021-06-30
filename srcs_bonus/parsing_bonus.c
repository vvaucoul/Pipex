/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:49:55 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 10:04:57 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static	int	check_existing(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	return (1);
}

static	int	check_access(t_pipex_b *pb, int i)
{
	char	**tmp;
	char	*path;

	tmp = ft_split(pb->args[i].data, ' ');
	path = ft_access_path(tmp[0], pb->envp);
	if (!path)
	{
		ft_free_tab(tmp);
		return (-1);
	}
	ft_free_tab(tmp);
	free(path);
	return (0);
}

static int	check_access_loop(t_pipex_b *pb)
{
	size_t	i;

	i = 1;
	while (i < pb->nb_args - 1)
	{
		if (check_access(pb, i) < 0)
			return (-1);
		++i;
	}
	return (0);
}

int	parsing_bonus(t_pipex_b *pb, size_t argc, char **argv)
{
	size_t	i;

	i = 1;
	while (i < argc)
	{
		add_arg_bonus(pb, create_arg((void *)argv[i]));
		++i;
	}
	ft_print_lst_bonus(pb);
	if (ft_strncmp(pb->args[0].data, HERE_DOC, ft_strlen(pb->args[0].data)))
	{
		if (check_access_loop(pb) < 0
			|| (!(check_existing(pb->args[0].data))))
			return (ft_err("Error : arguments invalid", -1, 0));
	}
	else
	{
		if ((check_access(pb, 2)) < 0
			|| ((check_access(pb, 3)) < 0)
			|| (pb->nb_args != 5
				&& pb->nb_args != 4))
			return (ft_err("Error : arguments invalid", -1, 0));
		pb->use_here_doc = 1;
	}
	return (0);
}
