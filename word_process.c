/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:14:46 by antimit           #+#    #+#             */
/*   Updated: 2024/10/19 19:28:38 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	skip_chars(const char *str, int i, char sep, int mode)
{
	if (mode == 0)
		while (str[i] && str[i] == sep)
			i++;
	else
		while (str[i] && str[i] != sep)
			i++;
	return (i);
}

size_t	count_words(const char *str, char sep)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		i = skip_chars(str, i, sep, 0);
		if (str[i] && str[i] != sep)
			count++;
		i = skip_chars(str, i, sep, 1);
	}
	return (count);
}

char	*ft_word(const char *str, char sep)
{
	int		i;
	int		len;
	char	*result;

	len = 0;
	while (str[len] && str[len] != sep)
		len++;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
