/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-kham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:30:26 by yal-kham          #+#    #+#             */
/*   Updated: 2024/10/07 13:30:27 by yal-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * neg);
}
/*
int main(void)
{
    printf("%d\n", ft_atoi("123"));
    printf("%d\n", ft_atoi("-123"));
    printf("%d\n", ft_atoi("+456"));
    printf("%d\n", ft_atoi("   789"));
    printf("%d\n", ft_atoi("  -42  "));
    printf("%d\n", ft_atoi("0"));
    printf("%d\n", ft_atoi("2147483647"));
    printf("%d\n", ft_atoi("-2147483648")); // INT_MIN
    printf("%d\n", ft_atoi("   +42abc"));   // should stop at abc
    printf("%d\n", ft_atoi("abc42"));             // should return 0

    return 0;
}*/
