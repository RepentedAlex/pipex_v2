/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:09:26 by apetitco          #+#    #+#             */
/*   Updated: 2024/02/29 22:44:24 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_count_tokens(char const *str, char sep)
{
	int	token_count;
	int	i;
	int	is_word;

	token_count = 0;
	i = 0;
	is_word = 0;
	if (str[i] && str[i] != sep)
	{
		is_word = 1;
		token_count++;
	}
	while (str[i])
	{
		if (str[i] != sep && !is_word)
		{
			is_word = 1;
			token_count++;
		}
		else if (str[i] == sep && is_word)
			is_word = 0;
		i++;
	}
	return (token_count);
}

static char	*ft_copy_words(const char *str, char sep, size_t *p)
{
	size_t	i;
	size_t	len_and_j;
	char	*word;

	i = 0;
	len_and_j = 0;
	while (str[i] && str[i] == sep)
		i++;
	while (str[i] && str[i] != sep)
	{
		len_and_j++;
		i++;
	}
	word = ft_calloc(len_and_j + 1, sizeof(char));
	if (!word)
		return (NULL);
	i -= len_and_j;
	len_and_j = 0;
	while (str[i] && str[i] != sep)
		word[len_and_j++] = str[i++];
	*p = i;
	word[len_and_j] = 0;
	return (word);
}

static void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tokens_array;
	size_t	token_count;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	token_count = (ft_count_tokens(s, c));
	tokens_array = ft_calloc(token_count + 1, sizeof(char *));
	if (!tokens_array)
		return (NULL);
	i = 0;
	while (i < token_count)
	{
		tokens_array[i] = ft_copy_words(s, c, &j);
		if (!tokens_array[i])
		{
			ft_free_tab(tokens_array);
			return (NULL);
		}
		s += j;
		i++;
	}
	tokens_array[i] = NULL;
	return (tokens_array);
}

/*
#include <stdio.h>


int	main(void)
{
	char	*original = "";
	char	separator = ' ';
	char	**tokens_array;

	tokens_array = ft_split(original, separator);
	for (int i = 0 ; tokens_array[i] != 0 ; i++)
		printf("Tokens_array[%d] : %c\n", i, tokens_array[i]);
	freeTab(tokens_array);
}
*/
