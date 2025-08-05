/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:09:51 by squinn            #+#    #+#             */
/*   Updated: 2025/08/05 18:29:03 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(s + i);
		i++;
	}
}


#include <stdio.h>

int main() {
  char *str = "MakeColorRed";
  ft_striter(str, &ft_toupper);
  printf("%s\n", str);
}
