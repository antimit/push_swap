/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antimit <antimit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:14:12 by antimit           #+#    #+#             */
/*   Updated: 2024/10/19 19:26:27 by antimit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split, size_t i)
{
	while (i > 0)
	{
		free(split[i - 1]);
		i--;
	}
	free(split);
}

// int	skip_chars(const char *str, int i, char sep, int mode)
// {
// 	if (mode == 0)
// 		while (str[i] && str[i] == sep)
// 			i++;
// 	else
// 		while (str[i] && str[i] != sep)
// 			i++;
// 	return (i);
// }

// size_t	count_words(const char *str, char sep)
// {
// 	size_t	count;
// 	int		i;

// 	count = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		i = skip_chars(str, i, sep, 0);
// 		if (str[i] && str[i] != sep)
// 			count++;
// 		i = skip_chars(str, i, sep, 1);
// 	}
// 	return (count);
// }

// char	*ft_word(const char *str, char sep)
// {
// 	int		i;
// 	int		len;
// 	char	*result;

// 	len = 0;
// 	while (str[len] && str[len] != sep)
// 		len++;
// 	result = (char *)malloc(len + 1);
// 	if (!result)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		result[i] = str[i];
// 		i++;
// 	}
// 	result[i] = '\0';
// 	return (result);
// }

char	**init_result(const char *s, char c)
{
	char	**result;

	result = (char **)malloc((count_words(s, c) + 2) * sizeof(char *));
	if (!result)
		return (NULL);
	result[0] = (char *)malloc(1);
	if (!result[0])
	{
		free(result);
		return (NULL);
	}
	result[0][0] = '\0';
	return (result);
}

int	process_words(char **result, const char *s, char c)
{
	size_t	i;
	int		start;
	char	*word;

	i = 1;
	start = 0;
	while (s[start])
	{
		start = skip_chars(s, start, c, 0);
		if (s[start] && s[start] != c)
		{
			word = ft_word(s + start, c);
			if (!word)
				return (free_split(result, i), 0);
			result[i++] = word;
		}
		start = skip_chars(s, start, c, 1);
	}
	result[i] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = init_result(s, c);
	if (!result)
		return (NULL);
	if (!process_words(result, s, c))
		return (NULL);
	return (result);
}

// int	main(void)
// {
// 	char **result;
// 	result = ft_split("Hello World", ' ');
// 	int i;
// 	i = 0;
// 	while (i < 3)
// 	{
// 		if (i == 0)
// 		{
// 			printf("%s", result[i]);
// 			i++;
// 			continue;;
// 		}
// 		printf("%s\n", result[i]);

// 		i++;
// 	}
// }