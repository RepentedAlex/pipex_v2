/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:44:46 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/19 15:49:41 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

static void	ft_free_get_path(char **cmds_array, char **all_paths)
{
	if (cmds_array)
		ft_free_tab(cmds_array);
	if (all_paths)
		ft_free_tab(all_paths);
}

static bool	ft_check(char *cmd, char *envp[])
{
	int		i;
	char	*exec;
	char	**all_paths;
	char	*part_path;
	char	**cmds_array;

	if (ft_strchr(cmd, '/'))
		if (access(cmd, F_OK) == 0)
			return (true);
	i = 0;
	all_paths = ft_split(get_env(envp), ':');
	cmds_array = ft_split(cmd, ' ');
	while (all_paths && all_paths[i])
	{
		part_path = ft_strjoin(all_paths[i], "/");
		exec = ft_strjoin(part_path, cmds_array[0]);
		free(part_path);
		if (access(exec, F_OK | X_OK) == 0)
			return (ft_free_tab(cmds_array), ft_free_tab(all_paths), \
			free(exec), true);
		free(exec);
		i++;
	}
	ft_free_get_path(cmds_array, all_paths);
	return (false);
}

bool	ft_check_commands(char *cmd1, char *cmd2, char *envp[])
{
	bool	bool_cmd1;
	bool	bool_cmd2;

	bool_cmd1 = ft_check(cmd1, envp);
	bool_cmd2 = ft_check(cmd2, envp);
	if (bool_cmd1 == false && bool_cmd2 == false)
		return (false);
	return (true);
}

/*
 * @brief Open the file and returns file_fd_out
 * @param infile the file path to be open in read only
 * @param outfile the file path to be open in write only, creating it if
 * 		necessary, truncating otherwise
 * @param file_fd_out[out] the file descriptor of both files opened. must be
 * 		at least an int[2]
 * @return false in case of error, true in case of success
 * */
bool	open_files(char *infile, char *outfile, int *file_fd_out)
{
	file_fd_out[0] = -1;
	file_fd_out[1] = -1;
	file_fd_out[0] = open(infile, O_RDONLY);
	if (file_fd_out[0] == -1)
		return (false);
	file_fd_out[1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_fd_out[1] == -1)
		return (close(file_fd_out[1]), false);
	return (true);
}
