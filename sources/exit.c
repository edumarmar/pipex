/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmartin <edmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:59:30 by edmartin          #+#    #+#             */
/*   Updated: 2021/12/10 17:31:46 by edmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_pipex(int option)
{
	if (option == 0)
		perror("Error: Not enough arguments");
	if (option == 1)
		perror("Error: input file does not exist");
	if (option == 2)
		perror("Error: input file empty");
	if (option == 3)
		perror("Error: pipe not built");
	if (option == 4)
		perror("Error: fork did not work");
	if (option == 5)
		perror("Error: command not found");
	if (option == 6)
		exit(0);
	exit(1);
}

void	free_utils_and_exit(t_utils *utils, int state)
{
	free_pipex(utils->cmd1);
	free_pipex(utils->cmd2);
	if (utils->paths != NULL)
		free_pipex(utils->paths);
	exit(state);
}

void	free_pipex(char **char_arr)
{
	int	i;

	i = 0;
	while (char_arr[i])
	{
		free(char_arr[i]);
		i++;
	}
	free(char_arr);
}
