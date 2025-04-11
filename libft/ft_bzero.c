/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-kham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:31:03 by yal-kham          #+#    #+#             */
/*   Updated: 2024/10/07 13:31:06 by yal-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	ft_memset(s, 0, len);
}
/*
int main(void)
{
	char buffer[20];

	// Initialize buffer with some values
	strcpy(buffer, "Hello, World!");

	printf("Before ft_bzero: '%s'\n", buffer);

	// Use ft_bzero to set the first 6 bytes to zero
	ft_bzero(buffer, 6);

	printf("After ft_bzero: '%s'\n", buffer);

	return 0;
}*/
