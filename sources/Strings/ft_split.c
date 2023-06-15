/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:08:31 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/14 21:23:03 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	clear_matrix(char **matrix)
{
	char	**temp;

	temp = matrix;
	while (temp)
	{
		free(*temp);
		temp++;
	}
	free(matrix);
}

static void	copy_word(char const *string, char *word, char delimiter, \
						size_t *index)
{
	size_t	position;

	position = 0;
	while (string[*index] != delimiter && string[*index])
	{
		word[position] = string[*index];
		position++;
		(*index)++;
	}
	word[position] = '\0';
}

static size_t	get_word_size(char const *string, char delimiter)
{
	size_t	size;

	size = 0;
	while (string[size] != delimiter && string[size])
		size++;
	return (size);
}

static char	**allocate_strings(char const *string, char delimiter, \
								char **matrix, size_t words)
{
	size_t	index;
	size_t	line;

	index = 0;
	line = 0;
	while (string[index] && line < words)
	{
		while (string[index] == delimiter)
			index++;
		matrix[line] = (char *)malloc(get_word_size(string + index, delimiter) \
										+ 1);
		if (matrix[line] == 0x0)
		{
			clear_matrix(matrix);
			return (0x0);
		}
		copy_word(string, matrix[line], delimiter, &index);
		line++;
	}
	matrix[line] = 0x0;
	return (matrix);
}

/**
 * @brief Allocates a matrix and split a string into words using a delimiter;
 * 
 * @param s A pointer to the string to be split;
 * @param c The delimiter character;
 * @return A pointer to the matrix of strings (char **); Otherwise NULL if 
 * 			allocation fails or if the string is NULL;
 */
char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	index;
	size_t	words;

	if (s == 0x0)
		return (0x0);
	index = 0;
	words = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index] != c && s[index])
			words++;
		while (s[index] != c && s[index])
			index++;
	}
	matrix = (char **)malloc(sizeof(char *) * (words + 1));
	if (matrix == 0x0)
		return (0x0);
	return (allocate_strings(s, c, matrix, words));
}
