/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:11:52 by apetitco          #+#    #+#             */
/*   Updated: 2024/02/29 22:42:53 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)s;
	while (i < n)
	{
		if (*(temp + i) == (unsigned char)c)
			return (temp + i);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*test = "Lee Kang-In";
	int		c = 'z';
	size_t	n = 11;

	char	*found = ft_memchr(test, c, n);
	if (found != NULL)
		printf("%s\n", found);
	else
		printf("Byte not found.\n");
}
*/
