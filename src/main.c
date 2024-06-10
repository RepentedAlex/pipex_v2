/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:17:16 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/10 14:01:03 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

/**
 * Executes a command with the given arguments.
 *
 * @param cmd The command to execute.
 * @param envp The environment variables.
 */
void	execute(char *cmd, char *envp[])
{
	char	**cmds_array;
	char	*path;

	cmds_array = ft_split(cmd, ' ');
	path = get_path(cmds_array[0], envp);
	if (execve(path, cmds_array, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
		ft_putendl_fd(cmds_array[0], STDERR_FILENO);
		ft_free_tab(cmds_array);
		exit(127);
	}
}

/**
 * Executes the child process in the pipex program.
 *
 * @param argv The command-line arguments passed to the program.
 * @param p_fd The file descriptors for the pipe.
 * @param envp The environment variables passed to the program.
 */
void	child(char *argv[], int *p_fd, char *envp[])
{
	int	fd;

	fd = open_file(argv[1], 0);
	dup2(fd, STDIN_FILENO);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[0]);
	execute(argv[2], envp);
}

/**
 * Executes the parent process.
 *
 * @param argv The command-line arguments.
 * @param p_fd The file descriptors for the pipe.
 * @param envp The environment variables.
 */
void	parent(char *argv[], int *p_fd, char *envp[])
{
	int	fd;

	fd = open_file(argv[4], 1);
	dup2(fd, STDOUT_FILENO);
	dup2(p_fd[0], STDIN_FILENO);
	close(p_fd[1]);
	execute(argv[3], envp);
}

/**
	@brief Handles the exit of the program.
	@param pid The process ids to wait.
	@param pipes The file descriptors of the pipe to close in case of error.
	@return The process id of the forked process or -1 in case of error.
*/
int	ft_fork(int *pid, int *pipes)
{
	int	ret;

	ret = fork();
	if (ret == -1)
	{
		close(pipes[0]);
		close(pipes[1]);
		if (pid[0] != 0)
			waitpid(pid[0], NULL, 0);
		if (pid[1] != 0)
			waitpid(pid[1], NULL, 0);
		ft_putstr_fd("Error: fork failed\n", STDERR_FILENO);
		exit(1);
	}
	return (ret);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		p_fd[2];
	pid_t	pid[2];

	if (argc != 5)
		exit_handler(1);
	(ft_bzero(pid, sizeof(pid)), ft_bzero(p_fd, sizeof(p_fd)));
	if (pipe(p_fd) == -1)
		(ft_putstr_fd("Error: pipe creation failed\n", 2), exit(127));
	pid[0] = ft_fork(pid, p_fd);
	if (pid[0] == 0)
		child(argv, p_fd, envp);
	pid[1] = ft_fork(pid, p_fd);
	if (pid[1] == 0)
		parent(argv, p_fd, envp);
	(close(p_fd[0]), close(p_fd[1]));
	(waitpid(pid[0], NULL, 0), waitpid(pid[1], NULL, 0));
	return (0);
}
