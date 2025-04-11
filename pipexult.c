/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-kham <yal-kham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:47:15 by yal-kham          #+#    #+#             */
/*   Updated: 2025/01/03 13:09:52 by yal-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_command(char *cmd, char **path)
{
	int		i;
	char	*path_str;
	char	*temp_str;

	i = 0;
	while (path[i])
	{
		temp_str = ft_strjoin(path[i], "/");
		if (!temp_str)
			return (NULL);
		path_str = ft_strjoin(temp_str, cmd);
		free(temp_str);
		if (!path_str)
			return (NULL);
		if (access(path_str, X_OK) == 0)
			return (path_str);
		free(path_str);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char *envp[])
{
	int		i;
	char	**path;
	char	*path_str;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path = ft_split(envp[i] + 5, ':');
	if (!path)
	{
		return (NULL);
		exit (1);
	}
	path_str = find_command(cmd, path);
	free_2d_array(path);
	return (path_str);
}
