/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:19:44 by emrul             #+#    #+#             */
/*   Updated: 2025/11/07 11:21:09 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

void	free_words(char **word_arr)
{
	int	i;

	i = 0;
	while (word_arr[i])
	{
		free(word_arr[i]);
		i++;
	}
	free(word_arr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (is_space(s[i]))
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*s_string;
	size_t		i;
	size_t		size;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	if (size - start > len)
		size = len;
	else
		size = size - start;
	s_string = (char *)malloc(sizeof(char) * (size + 1));
	if (!s_string)
		return (0);
	i = 0;
	while (i < size)
	{
		s_string[i] = s[start + i];
		i++;
	}
	s_string[i] = '\0';
	return (s_string);
}
