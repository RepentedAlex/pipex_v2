/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:17:16 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/19 15:59:39 by apetitco         ###   ########.fr       */
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
		free(path);
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
void	child(char *argv[], int *p_fd, char *envp[], int *files_fd)
{
	dup2(files_fd[0], STDIN_FILENO);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[0]);
	close(p_fd[1]);
	close(files_fd[1]);
	close(files_fd[0]);
	execute(argv[2], envp);
}

/**
 * Executes the parent process.
 *
 * @param argv The command-line arguments.
 * @param p_fd The file descriptors for the pipe.
 * @param envp The environment variables.
 */
void	parent(char *argv[], int *p_fd, char *envp[], int *files_fd)
{
	dup2(p_fd[0], STDIN_FILENO);
	dup2(files_fd[1], STDOUT_FILENO);
	close(p_fd[0]);
	close(p_fd[1]);
	close(files_fd[1]);
	close(files_fd[0]);
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
	int		files_fd[2];
	int		pipe_fd[2];
	pid_t	pid[2];

	if (argc != 5)
		exit_handler(1, NULL);
	if (!open_files(argv[1], argv[4], files_fd))
		exit_handler(5, NULL);
	if (!ft_check_commands(argv[2], argv[3], envp))
		exit_handler(3, files_fd);
	(ft_bzero(pid, sizeof(pid)), ft_bzero(pipe_fd, sizeof(pipe_fd)));
	if (pipe(pipe_fd) == -1)
		exit_handler(2, files_fd);
	pid[0] = ft_fork(pid, pipe_fd);
	if (pid[0] == 0)
		child(argv, pipe_fd, envp, files_fd);
	pid[1] = ft_fork(pid, pipe_fd);
	if (pid[1] == 0)
		parent(argv, pipe_fd, envp, files_fd);
	(close(pipe_fd[0]), close(pipe_fd[1]));
	(close(files_fd[0]), close(files_fd[1]));
	(close(STDIN_FILENO), close(STDOUT_FILENO), close(STDERR_FILENO));
	(waitpid(pid[0], NULL, 0), waitpid(pid[1], NULL, 0));
	return (0);
}
