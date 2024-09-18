/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiaz-to <ddiaz-to@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:56:29 by ddiaz-to          #+#    #+#             */
/*   Updated: 2024/09/11 10:56:29 by ddiaz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <unistd.h>

// ! ESTRUCTURA PRINCIPAL

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		input;
	int		output;
	char	*paths;
	char	**commands_paths;
	char	**commands_arg;
	char	*command;
}			t_pipex;

// ! MAIN

int			main(int argc, char **argv, char **envp);

// * ERRORES

void		ft_error_msg(char *str);

// * FN PARA MANEJAR ESTRUCTURA

char		*ft_find_path(char **envp);

// * FN AUXILIARES

char		*ft_strjoin(char *str1, char *str2);
int			ft_strncmp(const char *src, const char *str, int n);
char		*get_command(char **paths, char *command_arg);
void		proc_one(t_pipex pipex, char **argv, char **envp);
void		proc_two(t_pipex pipex, char **argv, char **envp);
void		end_both_proc(t_pipex pipex);
void		close_pipex(t_pipex *pipex);

// * FT_SPLIT

char		**ft_split(char const *s, char c);
char		**ft_empty_split(void);
int			ft_count_strings(char const *s, char c);
char		*ft_strdup(const char *s, size_t n);
char		**ft_free_str(char **aux);

// * LIBERAR MEMORIA

void		free_proc(t_pipex *pipex);
void		fork_free(t_pipex *pipex);

#endif

/*
typedef struct s_pipex
{
	pid_t pid1;            // Identificador del primer proceso hijo
	pid_t pid2;            // Identificador del segundo proceso hijo
	int tube[2];           // Tubería: tube[0] para leer, tube[1] para escribir
	int input;             // Descriptor del archivo de entrada
	int output;            // Descriptor del archivo de salida
	char *paths;           // Cadena que contiene las rutas de la variable PATH
	char **commands_paths; // Arreglo de rutas extraídas de PATH
	char **commands_arg;   // Arreglo con los argumentos de los comandos
	char *command;         // Comando a ejecutar con su ruta completa
}			t_pipex;
*/