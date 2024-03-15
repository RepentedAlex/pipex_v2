/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:28:23 by apetitco          #+#    #+#             */
/*   Updated: 2024/02/29 22:43:29 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	i;

	length = 0;
	i = 0;
	if (size == 0)
		return (ft_strlen((char *)src));
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[length] != '\0')
		length++;
	return (length);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*src = "Kang-In Lee";
	char	*dst = "qwertyuiopa";
	size_t	size = 7;

	size_t	result = ft_strlcpy(dst, src, size);
	printf("Resultat ft: %zu\n", result);
}
*/
