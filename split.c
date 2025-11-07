/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:38:20 by emrul             #+#    #+#             */
/*   Updated: 2025/11/07 11:23:12 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_bzero(void *s, size_t n)
{
	char	*s_updated;

	s_updated = (char *)s;
	while (n)
	{
		*s_updated = '\0';
		s_updated++;
		n--;
	}
	return ;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*al_mem;

	al_mem = malloc(nmemb * size);
	if (!al_mem)
		return (0);
	ft_bzero(al_mem, nmemb * size);
	return (al_mem);
}

static size_t	calc_word(char const *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (!is_space(*s) && (is_space(*(s + 1)) || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static char	*add_words(char const **s)
{
	char	*tmp;
	int		i_word;

	i_word = 0;
	while (is_space(**s))
		(*s)++;
	while (!is_space((*s)[i_word]) && (*s)[i_word])
		i_word++;
	tmp = ft_substr(*s, 0, i_word);
	if (!tmp)
		return (0);
	*s = *s + i_word;
	return (tmp);
}

char	**ft_split(char const *s)
{
	size_t	count;
	int		word_i;
	char	**word_arr;
	char	*tmp;

	count = calc_word(s);
	word_i = 0;
	word_arr = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!word_arr)
		return (0);
	while (count)
	{
		tmp = add_words(&s);
		if (!tmp)
		{
			free_words(word_arr);
			return (0);
		}
		word_arr[word_i] = tmp;
		word_i++;
		count--;
	}
	word_arr[word_i] = 0;
	return (word_arr);
}
