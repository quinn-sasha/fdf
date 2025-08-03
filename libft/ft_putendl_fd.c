/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:52:09 by squinn            #+#    #+#             */
/*   Updated: 2025/08/03 16:39:31 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(STDOUT_FILENO, s + i, 1);
		i++;
	}
	write(STDERR_FILENO, "\n", 1);
}
