/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiaz-to <ddiaz-to@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:58:33 by ddiaz-to          #+#    #+#             */
/*   Updated: 2024/09/11 10:58:33 by ddiaz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	end_both_proc(t_pipex pipex)
{
	close_pipex(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_proc(&pipex);
}

void	close_pipex(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

// FN PARA MOSTRAR ERRORES
void	ft_error_msg(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(1);
}

// FN PARA BUSCAR LA VARIABLE DE ENTORNO "PATH" EN ENVP

char	*ft_find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

// MAIN

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (*envp == NULL || argc != 5)
		ft_error_msg("ERROR: Missing env. variables!");
	pipex.input = open(argv[1], O_RDONLY);
	if (pipex.input == -1)
		ft_error_msg("ERROR: Can't open file");
	pipex.output = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex.output == -1)
		ft_error_msg("ERROR: Can't open file");
	if (pipe(pipex.tube) < 0)
		ft_error_msg("ERROR: Fail creating pipe");
	pipex.paths = ft_find_path(envp);
	pipex.commands_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		proc_one(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		proc_two(pipex, argv, envp);
	end_both_proc(pipex);
	return (0);
}
