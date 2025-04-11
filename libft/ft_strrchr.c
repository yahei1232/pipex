/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-kham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:39:53 by yal-kham          #+#    #+#             */
/*   Updated: 2024/10/07 13:39:55 by yal-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	const char		*rtn;

	uc = (unsigned char) c;
	rtn = 0;
	while (*s != '\0')
	{
		if (*s == uc)
			rtn = s;
		s++;
	}
	if (uc == '\0')
		rtn = s;
	return ((char *)rtn);
}
