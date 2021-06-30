/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:13:36 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 09:19:45 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	char	*get_env_path(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		if (!(ft_strncmp(envp[i], "PATH", 4)))
			return (&*envp[i] + 5);
		++i;
	}
	return (NULL);
}

char	*ft_access_path(char *cmd, char **envp)
{
	char	**tab;
	char	*path;
	char	*tmp;
	size_t	i;

	path = get_env_path(envp);
	tab = ft_split(path, ':');
	i = 0;
	while (tab[i])
	{
		tmp = ft_multijoin((char *[]){tab[i], "/", cmd, NULL});
		if (access(tmp, F_OK) == 0)
		{
			ft_free_tab(tab);
			return (tmp);
		}
		else
			free(tmp);
		++i;
	}
	ft_free_tab(tab);
	return (NULL);
}
