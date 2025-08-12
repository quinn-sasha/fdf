/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_libft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:05:24 by squinn            #+#    #+#             */
/*   Updated: 2025/08/12 08:20:37 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	make_upper(unsigned int i, char *c)
{
	(void)i;
	*c = ft_toupper(*c);
}

int	count_num_cols(char *line)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
		{
			i++;
			continue ;
		}
		while (line[i] && line[i] != ' ')
		{
			i++;
		}
		result++;
	}
	return (result);
}

void	*free_words(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
