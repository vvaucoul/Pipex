/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:54:48 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/06/23 10:07:09 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "pipex.h"

# define HERE_DOC "here_doc"
# define HERE_DOC_FILE_NAME ".tmp_infile.hdc"
# define HERE_DOC_PERM 0644

# define MAX_CHAR_PROMPT	4096

typedef struct s_cpipe
{
	pid_t			pid;
	int				status;
}	t_cpipe;

typedef struct s_m_pipe
{
	char			***pipe_tab;
	int				current_pipe;
	int				fd_current[2];
	int				fd_prev;
	size_t			nb_pipes;
	int				nb_args;
	int				pipe_valid;
	t_cpipe			*ac_pipes;
}	t_m_pipe;

typedef struct s_pipex_b
{
	t_arg		*args;
	char		**envp;
	size_t		nb_args;
	t_m_pipe	pipes;

	int			use_here_doc;
	char		**here_doc_tab;
}	t_pipex_b;

/*
**	CORE BONUS
*/

t_pipex_b		pipex_bonus_init(size_t argc, char **envp);
void			free_pipex_bonus(t_pipex_b *pb);
int				parsing_bonus(t_pipex_b *p, size_t argc, char **argv);
int				process_pipex_bonus(t_pipex_b *pb);
void			add_arg_bonus(t_pipex_b *pb, t_arg arg);
int				exec_cmd_pipe_bonus(t_pipex_b *pb, char **tab);

/*
**	HERE_DOC
*/

int				process_here_doc(t_pipex_b *pb);
int				init_here_doc(t_pipex_b *pb);
int				add_here_doc_line(t_pipex_b *pb, char *str);
int				write_heredoc_file(t_pipex_b *pb);

/*
**	MULTI PIPES
*/

int				init_pipes(t_pipex_b *pb);
int				first_pipe(t_pipex_b *pb);
int				last_pipe(t_pipex_b *pb);

int				redir_in(t_pipex_b *pb, t_arg infile);
int				redir_out(t_pipex_b *pb, t_arg outfile);
int				redir_double_out(t_pipex_b *pb, t_arg outfile);

/*
**	UTILS BONUS
*/

void			ft_print_lst_bonus(t_pipex_b *pb);
void			ft_print_pipes_bonus(char ***tab);
void			*ft_ternary(void *f1, void *f2, int condition);

#endif
