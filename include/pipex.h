/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:17:48 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/19 15:32:35 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# include <sys/wait.h>

void	exit_handler(int error_code, int *files_fd);
bool	ft_check_commands(char *cmd1, char *cmd2, char *envp[]);
void	ft_free_tab(char **tab);
char	*get_env(char *envp[]);
char	*get_path(char *cmd, char *envp[]);
bool	open_files(char *infile, char *outfile, int *file_fd_out);
void	child(char *argv[], int *p_fd, char *envp[], int *files_fd);
void	parent(char *argv[], int *p_fd, char *envp[], int *files_fd);
void	execute(char *cmd, char *envp[]);

#endif