/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:31:09 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 10:03:20 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

static	int	check_out(t_pipex_b *pb, char *current_line)
{
	if (current_line)
	{
		if (!ft_strncmp(current_line, pb->args[1].data,
				ft_strlen(pb->args[1].data)))
		{
			free(current_line);
			return (1);
		}
		else
		{
			if ((add_here_doc_line(pb, current_line)) < 0)
				return (-1);
		}
	}
	return (0);
}

static int	here_doc_read(char **current_line)
{
	char	buff;
	int		fc;

	if (*current_line)
		free(*current_line);
	*current_line = NULL;
	buff = 0;
	ft_putstr_fd("pipe heredoc> ", 1);
	while (buff != '\n')
	{
		fc = read(1, &buff, 1);
		if (fc < 0)
			return (ft_err("Error : Read : ", -1, 1));
		else if (buff != '\n')
			*current_line = ft_charjoin(*current_line, buff, 1);
	}
	return (0);
}

int	process_here_doc(t_pipex_b *pb)
{
	char	*current_line;
	int		ret;

	current_line = NULL;
	if ((init_here_doc(pb)) < 0)
		return (-1);
	while (1)
	{
		ret = check_out(pb, current_line);
		if (ret == -1)
			return (-1);
		else if (ret == 1)
			break ;
		if ((here_doc_read(&current_line)) < 0)
			return (-1);
	}
	if ((write_heredoc_file(pb)) < 0)
		return (-1);
	return (0);
}
