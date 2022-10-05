/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:38:05 by aionescu          #+#    #+#             */
/*   Updated: 2022/01/26 21:52:27 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/libft.h"

int	check_files(int argc, char **argv, int *fi_fo_po_pi)
{
	if (argc != 5)
	{
		write(1, "Error encountered: Number of arguments is not 4.\n", 50);
		return (1);
	}
	fi_fo_po_pi[0] = open(argv[1], O_RDONLY);
	fi_fo_po_pi[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fi_fo_po_pi[0] < 0 || fi_fo_po_pi[1] < 0)
	{
		if (fi_fo_po_pi[0] > 0)
			close(fi_fo_po_pi[0]);
		if (fi_fo_po_pi[1] > 0)
			close(fi_fo_po_pi[1]);
		write(1, "Error encountered: File(s) not available.\n", 43);
		return (1);
	}
	return (0);
}

char	*check_command(char *cmd, char **envp)
{
	int		envp_index;
	int		path_index;
	char	*cmd_path;
	char	**path_list;

	envp_index = 0;
	while (ft_strncmp("PATH=", envp[envp_index], 5) != 0
		&& envp[envp_index] != NULL)
		envp_index++;
	path_list = ft_split(envp[envp_index] + 5, ':');
	path_index = 0;
	while (path_list[path_index] != NULL)
	{
		cmd_path = strjoin_three(path_list[path_index], "/", cmd);
		if (access(cmd_path, X_OK) == 0)
		{
			free_string_arr(path_list);
			return (cmd_path);
		}
		free(cmd_path);
		path_index++;
	}
	free_string_arr(path_list);
	return (NULL);
}

void	check_pipe(int pipe_return, char *cmd, char *cmd_path)
{
	if (pipe_return < 0)
	{
		write(1, "Error encountered: Error piping.\n", 34);
		free(cmd);
		free(cmd_path);
		exit(1);
	}
}

void	check_fork(pid_t process_id, char *cmd, char *cmd_path)
{
	if (process_id < 0)
	{
		write(1, "Error encountered: Error forking.\n", 35);
		free(cmd);
		free(cmd_path);
		exit(1);
	}
}
