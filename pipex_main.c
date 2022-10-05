/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:32:21 by aionescu          #+#    #+#             */
/*   Updated: 2022/01/26 22:09:53 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/libft.h"

void	validate_commands(char *cmd, char *cmd_path, char **argv, char **envp)
{
	int	index;

	index = 3;
	while (index >= 2)
	{
		cmd = ft_split(argv[index], ' ')[0];
		cmd_path = check_command(cmd, envp);
		if (cmd_path == NULL)
		{
			write(1, "Error encountered: Invalid command.\n", 37);
			free(cmd);
			free(cmd_path);
			exit(2);
		}
		if (index > 2)
		{
			free(cmd);
			free(cmd_path);
		}
		index--;
	}
}

void	handle_child(char *cmd_path, char *argv, char **envp, int *fi_fo_po_pi)
{
	char	**cmd_arr;
	char	*cmd;

	cmd = ft_split(argv, ' ')[0];
	cmd_path = check_command(cmd, envp);
	cmd_arr = ft_split(argv, ' ');
	close(fi_fo_po_pi[2]);
	dup2(fi_fo_po_pi[0], STDIN_FILENO);
	dup2(fi_fo_po_pi[3], STDOUT_FILENO);
	execve(cmd_path, cmd_arr, envp);
	exit(127);
}

void	handle_parent(char *cmd_path, char *argv, char **envp, int *fi_fo_po_pi)
{
	char	**cmd_arr;

	cmd_arr = ft_split(argv, ' ');
	close(fi_fo_po_pi[3]);
	dup2(fi_fo_po_pi[2], STDIN_FILENO);
	dup2(fi_fo_po_pi[1], STDOUT_FILENO);
	execve(cmd_path, cmd_arr, envp);
	exit(127);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	process_id;
	int		fi_fo_po_pi[4];
	char	*cmd;
	char	*cmd_path;

	if (check_files(argc, argv, fi_fo_po_pi) != 0)
		return (1);
	cmd = NULL;
	cmd_path = NULL;
	validate_commands(cmd, cmd_path, argv, envp);
	check_pipe(pipe(fi_fo_po_pi + 2), cmd, cmd_path);
	process_id = fork();
	check_fork(process_id, cmd, cmd_path);
	if (process_id == 0)
		handle_child(cmd_path, argv[2], envp, fi_fo_po_pi);
	if (process_id > 0)
	{
		waitpid(process_id, NULL, WNOHANG);
		cmd = ft_split(argv[3], ' ')[0];
		cmd_path = check_command(cmd, envp);
		handle_parent(cmd_path, argv[3], envp, fi_fo_po_pi);
	}
	return (0);
}
