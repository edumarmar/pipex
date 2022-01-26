/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmartin <edmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:59:35 by edmartin          #+#    #+#             */
/*   Updated: 2022/01/26 15:41:39 by edmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_paths(char **envp)
{
	int		i;
	char	*str;
	char	**paths;
	char	*aux;

	i = 0;
	if (*envp == NULL)
		return (NULL);
	while (ft_strncmp(envp[i], "PATH", 4) && envp[i + 4])
		i++;
	if (envp[i + 4] == '\0')
		return (NULL);
	str = ft_strchr(envp[i], '/');
	paths = ft_split(str, ':');
	i = 0;
	while (paths[i])
	{
		aux = ft_strdup(paths[i]);
		free(paths[i]);
		paths[i] = ft_strjoin(aux, "/");
		free(aux);
		i++;
	}
	return (paths);
}

void	init_utils_2(t_utils *utils, char **argv, char **envp, int argc)
{
	char	**cmd1;
	char	**cmd2;

	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	utils->envp = envp;
	utils->cmd1 = cmd1;
	utils->argc = argc;
	utils->cmd2 = cmd2;
	utils->paths = parse_paths(envp);
}

t_utils	init_utils(int fd_files[2], int *fd_pipe)
{
	t_utils	utils;

	utils.fd_input = fd_files[0];
	utils.fd_output = fd_files[1];
	utils.fd_pipe = fd_pipe;
	return (utils);
}

void	try_first(t_utils *utils, int what_cmd)
{
	if (what_cmd == 2)
		execve(utils->cmd1[0], utils->cmd1, utils->envp);
	else
		execve(utils->cmd2[0], utils->cmd2, utils->envp);
}
