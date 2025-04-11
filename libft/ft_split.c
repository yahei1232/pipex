/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-kham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:37:09 by yal-kham          #+#    #+#             */
/*   Updated: 2024/10/07 13:37:10 by yal-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_toklen(char const *s, char c)
{
	size_t	res;
	size_t	i;

	res = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			res++;
			while (s[i] != 0 && s[i] != c)
				i++;
		}
		else
		{
			i++;
		}
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	res = malloc (sizeof(char *) * (ft_toklen(s, c) + 1));
	if (res == NULL || s == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			len = 0;
			while (s[i + len] != '\0' && s[i + len] != c)
				len++;
			res[j++] = ft_substr(s, i, len);
			i += len;
		}
		else
			i++;
	}
	res[j] = 0;
	return (res);
}
/*
int	main()
{
	char	**result;
	size_t	i;
	i = 0;
	result = ft_split(NULL, ',');
	if (!result)
    	{
		fprintf(stderr, "Error: ft_split failed.\n");
		return 1;
	}
	while (result[i] != 0)
	{
		printf("%s\n", result[i]);
		free(result[i]); 
		i++;
	}
	free(result);
	return 0;
}*/
