/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:29:03 by mamarin-          #+#    #+#             */
/*   Updated: 2025/07/03 10:43:18 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	c = (char)c;
	while (*ptr)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	if (*ptr == c)
	{
		return (ptr);
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = malloc(count * size);
	if (!mem)
		return (0);
	while (i < size * count)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	if (new == NULL)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (++i < len_s1)
		new[i] = s1[i];
	j = -1;
	while (++j < len_s2)
		new[i + j] = s2[j];
	free(s1);
	return (new);
}
