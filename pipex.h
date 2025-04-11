/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-kham <yal-kham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:34:18 by hassende          #+#    #+#             */
/*   Updated: 2025/01/04 14:16:50 by yal-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

char	*get_path(char *cmd, char *envp[]);
void	handle_path_error(char *cmd);
void	free_2d_array(char **arr);
void	error_exit(const char *msg);
void	dup_handl_error(char *dup2_message, int pipeFd[2], int fd);

#endif
