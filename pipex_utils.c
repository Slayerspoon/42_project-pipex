/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:48:08 by aionescu          #+#    #+#             */
/*   Updated: 2022/01/26 18:09:23 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/libft.h"

void	free_string_arr(char **string_arr)
{
	int	index;

	index = 0;
	while (string_arr[index] != NULL)
	{
		free(string_arr[index]);
		index++;
	}
	free(string_arr);
}

char	*strjoin_three(char *first, char *second, char *third)
{
	int		len_fst;
	int		len_snd;
	int		len_trd;
	char	*joint_str;

	if (first == NULL || second == NULL || third == NULL)
		return (NULL);
	len_fst = ft_strlen(first);
	len_snd = ft_strlen(second);
	len_trd = ft_strlen(third);
	joint_str = (char *)ft_calloc((len_fst + len_snd + len_trd + 1), 1);
	ft_strlcpy(joint_str, first, len_fst + 1);
	ft_strlcat(joint_str, second, len_fst + len_snd + 1);
	ft_strlcat(joint_str, third, len_fst + len_snd + len_trd + 1);
	return (joint_str);
}
