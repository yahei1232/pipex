/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-kham <yal-kham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:22:18 by yal-kham          #+#    #+#             */
/*   Updated: 2025/01/06 14:25:10 by yal-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(char *cmd, char *envp[])
{
	char	**arr_cmd;
	char	*path;

	if (!cmd || !*cmd)
		handle_path_error("");
	arr_cmd = ft_split(cmd, ' ');
	if (!arr_cmd || arr_cmd[0] == NULL)
		handle_path_error(cmd);
	if (access(cmd, X_OK) == 0)
		path = cmd;
	else
		path = get_path(arr_cmd[0], envp);
	if (path == NULL)
	{
		free_2d_array(arr_cmd);
		handle_path_error(cmd);
	}
	if (execve(path, arr_cmd, envp) == -1)
	{
		free(path);
		free_2d_array(arr_cmd);
		error_exit("execve failed");
	}
}

void	dofirstprocess(int pipeFd[2], char **path, char **cmd)
{
	int		fd;

	if (access(cmd[1], R_OK) == -1)
	{
		close(pipeFd[0]);
		close(pipeFd[1]);
		error_exit(cmd[1]);
	}
	fd = open(cmd[1], O_RDONLY);
	if (fd == -1)
		error_exit(cmd[1]);
	if (dup2(fd, 0) == -1)
		dup_handl_error("error on dup2", pipeFd, fd);
	if (dup2(pipeFd[1], 1) == -1)
		dup_handl_error("error on dup2", pipeFd, fd);
	close(pipeFd[0]);
	close(fd);
	close(pipeFd[1]);
	execute_command(cmd[2], path);
}

void	dosecoundprocess(int pipeFd[2], char **path, char **cmd)
{
	int	fd;

	fd = open(cmd[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Erorr on create");
		close(pipeFd[0]);
		close(pipeFd[1]);
		exit(1);
	}
	if (dup2(pipeFd[0], 0) == -1)
		dup_handl_error("error on dup2", pipeFd, fd);
	if (dup2(fd, 1) == -1)
		dup_handl_error("error on dup2", pipeFd, fd);
	close(pipeFd[0]);
	close(pipeFd[1]);
	close(fd);
	execute_command(cmd[3], path);
}

void	wait_for_children(void)
{
	int	status1;
	int	status2;

	if (waitpid(0, &status1, 0) == -1)
		error_exit("Error waiting for first child process");
	if (waitpid(0, &status2, 0) == -1)
		error_exit("Error waiting for second child process");
	if (WIFEXITED(status2))
		exit(WEXITSTATUS(status2));
	else
		exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	fork_id1;
	pid_t	fork_id2;

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex filein cmd1 cmd2 fileout\n", 2);
		exit (1);
	}
	if (pipe(pipe_fd) < 0)
		error_exit("Error on pipe");
	fork_id1 = fork();
	if (fork_id1 < 0)
		error_exit("Error on fork");
	if (fork_id1 == 0)
		dofirstprocess(pipe_fd, envp, argv);
	fork_id2 = fork();
	if (fork_id2 < 0)
		error_exit("Error on fork");
	if (fork_id2 == 0)
		dosecoundprocess(pipe_fd, envp, argv);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait_for_children();
	return (0);
}
