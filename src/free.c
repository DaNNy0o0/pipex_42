/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiaz-to <ddiaz-to@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:38:19 by ddiaz-to          #+#    #+#             */
/*   Updated: 2024/09/18 19:38:19 by ddiaz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_proc(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->input);
	close(pipex->output);
	while (pipex->commands_paths[i])
	{
		free(pipex->commands_paths[i]);
		i++;
	}
	free(pipex->commands_paths);
}

void	fork_free(t_pipex *pipex)
{
	int		i;

	i = 0;
	while (pipex->commands_arg[i])
	{
		free(pipex->commands_arg[i]);
		i++;
	}
	free(pipex->commands_arg);
	free(pipex->command);
}
