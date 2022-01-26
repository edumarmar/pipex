/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmartin <edmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:59:24 by edmartin          #+#    #+#             */
/*   Updated: 2022/01/26 15:42:19 by edmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(t_utils *utils, int what_cmd)
{
	int		i;
	char	*exec_cmd;

	i = 0;
	try_first(utils, what_cmd);
	while (utils->paths[i])
	{
		if (what_cmd == 2)
		{
			exec_cmd = ft_strjoin(utils->paths[i], utils->cmd1[0]);
			if (!exec_cmd)
				exit(1);
			execve(exec_cmd, utils->cmd1, utils->envp);
		}
		else
		{
			exec_cmd = ft_strjoin(utils->paths[i], utils->cmd2[0]);
			if (!exec_cmd)
				exit(1);
			execve(exec_cmd, utils->cmd2, utils->envp);
		}
		free(exec_cmd);
		i++;
	}
	exit_pipex(5);
}

void	child(t_utils *utils, int fd_stdin, int i)
{
	dup2(fd_stdin, STDIN_FILENO);
	if (i == utils->argc - 2)
		dup2(utils->fd_output, STDOUT_FILENO);
	else
		dup2(utils->fd_pipe[1], STDOUT_FILENO);
	exec(utils, i);
}

void	parent(t_utils *utils, int fd_stdin)
{
	waitpid(-1, NULL, 0);
	close(utils->fd_pipe[1]);
	close(fd_stdin);
	dup2(utils->fd_pipe[0], fd_stdin);
	close(utils->fd_pipe[0]);
}

void	pipex(t_utils *utils)
{
	pid_t	pid;
	int		fd_stdin;
	int		i;

	i = 2;
	fd_stdin = utils->fd_input;
	while (i < utils->argc - 1)
	{
		pid = fork();
		if (pid < 0)
			free_utils_and_exit(utils, 1);
		else if (pid == 0)
			child(utils, fd_stdin, i);
		else
			parent(utils, fd_stdin);
		i++;
	}
	free_utils_and_exit(utils, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_files[2];
	int		fd_pipe[2];
	t_utils	utils;

	if (argc != 5)
		exit_pipex(0);
	fd_files[0] = open(argv[1], O_RDONLY);
	fd_files[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_files[0] == -1 || fd_files[1] == -1)
		exit_pipex(1);
	if (pipe(fd_pipe) == -1)
		exit_pipex(3);
	utils = init_utils(fd_files, fd_pipe);
	init_utils_2(&utils, argv, envp, argc);
	pipex(&utils);
	return (0);
}
