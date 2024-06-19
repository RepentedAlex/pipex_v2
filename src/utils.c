/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:09:02 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/19 15:37:12 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

void	exit_handler(int error_code, int *files_fd)
{
	if (error_code == 1)
		ft_putstr_fd("./pipex infile cmd1 cmd2 outfile\n", STDERR_FILENO);
	else if (error_code == 2)
		ft_putstr_fd("Error: pipe creation failed\n", STDERR_FILENO);
	else if (error_code == 3)
		ft_putstr_fd("Error: command not found\n", STDERR_FILENO);
	else if (error_code == 4)
		ft_putstr_fd("Error: no environment\n", STDERR_FILENO);
	else if (error_code == 5)
		ft_putstr_fd("Error: Failed to open files\n", STDERR_FILENO);
	if (files_fd != NULL)
		(close(files_fd[0]), close(files_fd[1]));
	exit(127);
}

int	open_file(char *file, int io)
{
	int	ret;

	ret = 0;
	if (io == STDIN_FILENO)
		ret = open(file, O_RDONLY, 0777);
	else if (io == STDOUT_FILENO)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (ret == -1)
		exit(127);
	return (ret);
}

/**
 * Frees the memory allocated for a dynamically allocated array of strings.
 *
 * @param tab The array of strings to be freed.
 */
void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

/**
 * Retrieves the value of an environment variable.
 *
 * @param name The name of the environment variable.
 * @param envp An array of strings representing the environment variables.
 * @return The value of the environment variable if found, NULL otherwise.
 */
char	*get_env(char *envp[])
{
	int		i;
	int		j;
	char	*env_string;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		env_string = ft_substr(envp[i], 0, j);
		if (ft_strncmp(env_string, "PATH", j) == 0)
		{
			free(env_string);
			return (envp[i] + j + 1);
		}
		free(env_string);
		i++;
	}
	return (NULL);
}

/**
 * Retrieves the full path of a command by searching through the directories
 * specified in the PATH environment variable.
 *
 * @param cmd The command to find the path for.
 * @param envp The array of environment variables.
 * @return The full path of the command if found, otherwise the original command.
 */
char	*get_path(char *cmd, char *envp[])
{
	int		i;
	char	*exec;
	char	**all_paths;
	char	*part_path;
	char	**cmds_array;

	if (ft_strchr(cmd, '/'))
		return (cmd);
	i = 0;
	all_paths = ft_split(get_env(envp), ':');
	cmds_array = ft_split(cmd, ' ');
	while (all_paths[i])
	{
		part_path = ft_strjoin(all_paths[i], "/");
		exec = ft_strjoin(part_path, cmds_array[0]);
		free(part_path);
		if (access(exec, F_OK | X_OK) == 0)
			return (ft_free_tab(cmds_array), ft_free_tab(all_paths), exec);
		free(exec);
		i++;
	}
	ft_free_tab(cmds_array);
	ft_free_tab(all_paths);
	return (NULL);
}
