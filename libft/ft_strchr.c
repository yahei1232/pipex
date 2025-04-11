/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-kham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:37:20 by yal-kham          #+#    #+#             */
/*   Updated: 2024/10/07 13:37:21 by yal-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int n)
{
	while (*str)
	{
		if (*str == (char)n)
			return ((char *)str);
		str++;
	}
	if (*str == (char)n)
		return ((char *)str);
	return (0);
}
