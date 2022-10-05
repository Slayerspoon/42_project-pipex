/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:29:04 by aionescu          #+#    #+#             */
/*   Updated: 2022/01/26 21:22:30 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		check_files(int argc, char **argv, int *fin_fout_pin_pout);
char	*check_command(char *cmd, char **envp);
void	check_pipe(int pipe_return, char *cmd, char *cmd_path);
void	check_fork(pid_t process_id, char *cmd, char *cmd_path);
void	free_string_arr(char **string_arr);
char	*strjoin_three(char *first, char *second, char *third);

#endif
