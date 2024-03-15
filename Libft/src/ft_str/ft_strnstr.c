/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:08:24 by apetitco          #+#    #+#             */
/*   Updated: 2024/02/29 22:43:40 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	if (!ft_strlen((char *)little))
		return ((char *)big);
	while (n > 0 && *big)
	{
		if (*big == little[0] && \
		!ft_strncmp(big, little, ft_strlen((char *)little)) \
		&& ft_strlen((char *)little) <= n)
			return ((char *)big);
		big++;
		n--;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	char 	str1[] = "aaabcabcd";
	char 	str2[] = "aabc";

	(void)str2;
	char *str3 = ft_strnstr(str1, "a", -1);
	printf("%s", str3);
}
*/
