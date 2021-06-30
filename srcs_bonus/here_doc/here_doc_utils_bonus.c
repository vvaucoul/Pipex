/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:53:07 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 09:54:00 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

int	init_here_doc(t_pipex_b *pb)
{
	pb->here_doc_tab = (char **)ft_memalloc(sizeof(char *),
			MAX_CHAR_PROMPT * MAX_CHAR_PROMPT);
	if (!pb->here_doc_tab)
		return (ft_err("Error : Malloc : ", -1, 1));
	pb->here_doc_tab[0] = NULL;
	if (!pb->here_doc_tab)
		return (ft_err("Error : Malloc : ", -1, 1));
	return (0);
}

int	add_here_doc_line(t_pipex_b *pb, char *str)
{
	size_t	i;

	i = 0;
	while (pb->here_doc_tab[i])
		++i;
	pb->here_doc_tab[i] = ft_strdup(str);
	if (!pb->here_doc_tab[i])
		return (ft_err("Error : Malloc : ", -1, 1));
	pb->here_doc_tab[i + 1] = NULL;
	return (0);
}

int	write_heredoc_file(t_pipex_b *pb)
{
	int		fc;
	int		fd;
	size_t	i;

	fd = open(HERE_DOC_FILE_NAME, O_WRONLY | O_TRUNC | O_CREAT, HERE_DOC_PERM);
	i = 0;
	if (fd < 0)
		return (-1);
	while (pb->here_doc_tab[i])
	{
		fc = write(fd, pb->here_doc_tab[i], ft_strlen(pb->here_doc_tab[i]));
		if (fc < 0)
			return (fc);
		fc = write(fd, "\n", 1);
		if (fc < 0)
			return (ft_err("Error : Read : ", -1, 1));
		++i;
	}
	close(fd);
	return (0);
}
