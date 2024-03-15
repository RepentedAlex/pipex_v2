/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:16:59 by apetitco          #+#    #+#             */
/*   Updated: 2024/02/29 22:43:01 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dup_src;
	char	*dup_dest;

	if (!src && !dest)
		return (dest);
	dup_src = (char *)src;
	dup_dest = (char *)dest;
	i = 0;
	while (i < n)
	{
		dup_dest[i] = dup_src[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*original = "Kang-In Lee";
	char	*destination = "ooooooooooo";
	
	char	*d_original = strdup(original);
	char	*d_destination = strdup(destination);
	destination = ft_memcpy(d_destination, d_original, 12);
	printf("%s\n", d_destination);
}
*/
