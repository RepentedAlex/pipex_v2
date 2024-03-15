/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:15:33 by apetitco          #+#    #+#             */
/*   Updated: 2024/02/29 22:43:47 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	len_original;

	if (!s)
		return (NULL);
	substr = NULL;
	len_original = ft_strlen(s);
	if (start > len_original)
		return (ft_calloc(1, sizeof(char)));
	if (len >= ft_strlen((s + start)))
		substr = ft_calloc(len_original - start + 1, sizeof(char));
	else
		substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, (s + start), len + 1);
	return (substr);
}

/*
#include <stdio.h>

int	main(void)
{
	char			*original = "BONJOUR LES HARICOTS !";
	unsigned int	start = 8;
	size_t			len = 14;

	char	*result = ft_substr(original, start, len);
	printf("%s\n", result);
}
*/
