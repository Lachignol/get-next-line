/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:28:41 by ascordil          #+#    #+#             */
/*   Updated: 2024/12/06 11:28:07 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *theString)
{
	size_t	size;

	size = 0;
	while (*theString)
	{
		size++;
		theString++;
	}
	return (size);
}

char	*ft_strdup(const char *str)
{
	int				i;
	int				size_str;
	unsigned char	*result;

	i = 0;
	size_str = ft_strlen(str);
	result = malloc((sizeof(char) * size_str) + 1);
	if (!result)
		return (NULL);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return ((char *)result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	size_t	i;
	size_t	j;
	char	*result;

	i = -1;
	j = -1;
	if (!(s1) || !(s2))
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (total_size + 1));
	if (!result)
		return (NULL);
	while (j++, i++, s1[j])
		result[i] = s1[j];
	j = -1;
	i--;
	while (i++, j++, s2[j])
		result[i] = s2[j];
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	j;
	char			*result;
	size_t			stringlen;

	j = 0;
	if (!s)
		return (NULL);
	stringlen = ft_strlen(s);
	if (start >= stringlen)
		return (ft_strdup(""));
	if (start + len > stringlen)
		len = stringlen - start;
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	while (j < len)
	{
		result[j] = s[start + j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	*ft_strchr(const char *string, int searchedChar)
{
	if ((char)searchedChar == '\0')
		return ((char *)&string[ft_strlen(string)]);
	while (*string)
	{	
		if (*string == (char)searchedChar)
			return ((char *)string);
		string++;
	}
	return (NULL);
}
