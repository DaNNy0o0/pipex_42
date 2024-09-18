/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiaz-to <ddiaz-to@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:43:36 by ddiaz-to          #+#    #+#             */
/*   Updated: 2024/09/11 11:43:36 by ddiaz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_command(char **paths, char *command_arg)
{
	char	*aux;
	char	*exe;

	while (*paths)
	{
		aux = ft_strjoin(*paths, "/");
		exe = ft_strjoin(aux, command_arg);
		free(aux);
		if (access(exe, F_OK) == 0)
			return (exe);
		free(exe);
		paths++;
	}
	return (NULL);
}

void	proc_one(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.tube[1], 1);
	close(pipex.tube[0]);
	dup2(pipex.input, 0);
	pipex.commands_arg = ft_split(argv[2], ' ');
	pipex.command = get_command(pipex.commands_paths, pipex.commands_arg[0]);
	if (!pipex.command)
	{
		fork_free(&pipex);
		ft_error_msg("Commands not found");
		exit(1);
	}
	execve(pipex.command, pipex.commands_arg, envp);
}

void	proc_two(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.tube[0], 0);
	close(pipex.tube[1]);
	dup2(pipex.output, 1);
	pipex.commands_arg = ft_split(argv[3], ' ');
	pipex.command = get_command(pipex.commands_paths, pipex.commands_arg[0]);
	if (!pipex.command)
	{
		fork_free(&pipex);
		ft_error_msg("Commands not found");
		exit(1);
	}
	execve(pipex.command, pipex.commands_arg, envp);
}
