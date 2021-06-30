/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:23:43 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 10:06:42 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_arg
{
	char			*data;
}	t_arg;

typedef struct s_pipex
{
	t_arg			*args;
	char			**envp;
	size_t			nb_args;
	int				pipe_fd[2];
}	t_pipex;

t_pipex				pipex_init(size_t argc, char **envp);
int					parsing(t_pipex *p, size_t argc, char **argv);
void				free_pipex(t_pipex *p);
int					process_pipex(t_pipex *p);

/*
**	UTILS
*/

t_arg				create_arg(void *data);
void				add_arg(t_pipex *p, t_arg arg);
char				*ft_access_path(char *cmd, char **envp);

void				ft_putstr_fd(char *s, int fd);
void				ft_print_lst(t_pipex *p);
char				**ft_split(char *str, char c);
size_t				ft_strlen(char *str);
char				*ft_charjoin(char *str, char c, int tf);
char				*ft_strdup(char *s1);
void				ft_print_tab(char **tab);
int					ft_strncmp(char *s1, char *s2, size_t n);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_multijoin(char **tab);
void				*ft_memalloc(size_t size, size_t len);
int					ft_putstrerrno(int ret);
void				ft_free_tab(char **tab);
size_t				ft_args_size(t_arg *args, size_t nb_args);
int					ft_err(char *str, int err, int usererrno);

#endif
