/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmartin <edmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:22:27 by edmartin          #+#    #+#             */
/*   Updated: 2021/12/10 17:34:38 by edmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_utils
{
	int		fd_input;
	int		fd_output;
	char	**cmd1;
	char	**cmd2;
	char	**paths;
	char	**envp;
	int		argc;
	int		*fd_pipe;
}				t_utils;

char		**parse_paths(char **envp);
t_utils		init_utils(int fd_files[2], int *fd_pipe);
void		init_utils_2(t_utils *utils, char **argv, char **envp, int argc);
int			check_updatingfile(char *path);
void		try_first(t_utils *utils, int what_cmd);

void		free_utils_and_exit(t_utils *utils, int state);
void		exit_pipex(int option);
void		free_pipex(char **char_arr);

#endif
