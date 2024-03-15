/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:58:12 by apetitco          #+#    #+#             */
/*   Updated: 2024/02/29 22:43:26 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat_str;
	int		cat_len;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	cat_len = len_s1 + len_s2;
	cat_str = ft_calloc((cat_len) + 1, sizeof(char));
	if (!cat_str)
		return (NULL);
	ft_strlcpy(cat_str, s1, len_s1 + 1);
	ft_strlcat(cat_str, s2, len_s1 + len_s2 + 1);
	return (cat_str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s1 = "tripouille";
	char	*s2 = "42";

	char	*s3 = ft_strjoin(s1, s2);
	printf("%s\n", s3);
}
*/
