/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:47:18 by apetitco          #+#    #+#             */
/*   Updated: 2024/02/29 22:43:28 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	if (size == 0)
		return (ft_strlen((char *)src));
	src_len = ft_strlen((char *)src);
	dst_len = ft_strlen(dst);
	i = 0;
	if (size <= dst_len)
		return (size + src_len);
	while (src[i] && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = 0;
	return (dst_len + src_len);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*src = ft_strdup("Kang-In Lee");
	char	*dst = ft_strdup("qwertyuiopa");
	size_t	size = 7;

	size_t	result = ft_strlcat(dst, src, size);
	printf("Resultat ft_strlcat: %zu\n", result);
}
*/
