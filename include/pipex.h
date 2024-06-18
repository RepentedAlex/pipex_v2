/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:17:48 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/10 14:24:25 by apetitco         ###   ########.fr       */
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

void	child(char *argv[], int *p_fd, char *envp[]);
void	execute(char *cmd, char *envp[]);
void	exit_handler(int error_code);
void	ft_free_tab(char **tab);
char	*get_path(char *cmd, char *envp[]);
int		open_file(char *file, int io);
void	parent(char *argv[], int *p_fd, char *envp[]);

#endif