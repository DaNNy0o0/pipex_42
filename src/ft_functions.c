/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiaz-to <ddiaz-to@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:47:39 by ddiaz-to          #+#    #+#             */
/*   Updated: 2024/09/18 19:47:39 by ddiaz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	new = malloc((ft_strlen(str1) + ft_strlen(str2)) + 1);
	if (!new)
		return (NULL);
	while (str1[i] != '\0')
	{
		new[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j] != '\0')
	{
		new[i] = str2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

// FN PARA COMPARAR "N" CARACTERES DE UN STRING CON OTRO

int	ft_strncmp(const char *src, const char *str, int n)
{
	int	i;

	i = 0;
	while ((src[i] != '\0' || str[i] != '\0') && i < n)
	{
		if (src[i] != str[i])
			return ((const unsigned char)src[i] - (const unsigned char)str[i]);
		i++;
	}
	return (0);
}
