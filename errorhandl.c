/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-kham <yal-kham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:38:44 by yal-kham          #+#    #+#             */
/*   Updated: 2025/01/04 14:17:15 by yal-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_handl_error(char *dup2_message, int pipeFd[2], int fd)
{
	ft_putstr_fd(dup2_message, 2);
	close(pipeFd[0]);
	close(pipeFd[1]);
	close (fd);
	exit(1);
}

void	handle_path_error(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found \n", 2);
	exit (127);
}

void	error_exit(const char *msg)
{
	perror(msg);
	exit(1);
}

void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free(arr);
}
