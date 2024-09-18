/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiaz-to <ddiaz-to@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:52:20 by ddiaz-to          #+#    #+#             */
/*   Updated: 2024/09/11 11:52:20 by ddiaz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// * FN PARA VACIAR MEMORIA ASIGNADA EN CASO DE RECIBIR STR VACIO

char	**ft_empty_split(void)
{
	char	**aux;

	aux = (char **)malloc(sizeof(char *));
	if (!aux)
	{
		return (NULL);
	}
	aux[0] = NULL;
	return (aux);
}

// * FN PARA CONTAR SUBCADENAS

int	ft_count_strings(char const *s, char c)
{
	int	i;
	int	number_str;

	i = 0;
	number_str = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (number_str);
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			number_str++;
		i++;
	}
	return (number_str);
}

// * FN PARA DUPLICAR UNA CADENA

char	*ft_strdup(const char *s, size_t n)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (n == 0)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (n + 1));
	if (dst == 0)
		return (NULL);
	while (i < n)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

// * FN PARA LIBERAR MEMORIA ASIGNADA A UN ARRAY

char	**ft_free_str(char **aux)
{
	int	i;

	i = 0;
	while (aux[i])
	{
		free(aux[i]);
		i++;
	}
	free(aux);
	return (NULL);
}

// ! FT_SPLIT - PARA DIVIDIR CADENA RECIBIDA CON EL PATH EN SUBCADENAS
// ! DELIMITADAS POR "c" (:)

char	**ft_split(char const *s, char c)
{
	char	**final_arr;
	int		i;
	int		j;
	int		substr_start;

	i = 0;
	j = 0;
	if (!s || *s == '\0')
		return (ft_empty_split());
	final_arr = (char **)malloc(sizeof(char *) * (ft_count_strings(s, c) + 1));
	if (!final_arr)
		return (NULL);
	while (j < ft_count_strings(s, c) && s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		substr_start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		final_arr[j] = ft_strdup(&s[substr_start], i - substr_start);
		if (final_arr[j++] == NULL)
			return (ft_free_str(final_arr));
	}
	final_arr[j] = NULL;
	return (final_arr);
}
