/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-kham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:38:30 by yal-kham          #+#    #+#             */
/*   Updated: 2024/10/07 13:38:31 by yal-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	dlen;
	unsigned int	slen;
	unsigned int	i;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	i = 0;
	if (size <= dlen)
		return (size + slen);
	while (src[i] != '\0' && (dlen + i) < (size - 1))
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}
