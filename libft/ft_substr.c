/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:52:41 by squinn            #+#    #+#             */
/*   Updated: 2025/07/02 16:47:56 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	src_len;
	size_t	i;
	char	*new_string;

	if (len == 0)
		return (ft_strdup(""));
	src_len = ft_strlen(s);
	if (start >= src_len)
		return (ft_strdup(""));
	if (len > src_len - start)
		len = src_len - start;
	new_string = malloc(len + 1);
	if (!new_string)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_string[i] = s[i + start];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

/*
#include <stdio.h>

int	main(int argc, char *argv[]) {
	(void)argc;
	char const *s = argv[1];
	unsigned int start = atoi(argv[2]);
	size_t len = atoi(argv[3]);
	printf("Original string: %s\n", s);
	printf("Substring: %s\n", ft_substr(s, start, len));
}
*/
