/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:35:06 by jkassand          #+#    #+#             */
/*   Updated: 2021/11/27 13:15:04 by jkassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_lines(char const *s, char c)
{
	int	i;
	int	num;

	if (!c || !*s)
		return (1);
	num = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!num || s[i])
			num++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (num);
}

static char	*ft_str(char const *s, char c, int *i)
{
	char	*buf;
	int		j;
	int		len;

	if (c)
		while (s[*i] == c)
			(*i)++;
	len = *i;
	while (s[len] && s[len] != c)
		len++;
	buf = malloc(len - *i + 1);
	if (buf == NULL)
		return (NULL);
	j = 0;
	while (*i < len)
		buf[j++] = s[(*i)++];
	buf[j] = 0;
	return (buf);
}

void	free_page(char **page, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(page[i]);
		i++;
	}
	free(page);
}

char	**ft_split(char const *s, char c)
{
	char	**page;
	int		i;
	int		j;
	int		num;

	if (!s)
		return (NULL);
	num = ft_lines(s, c);
	page = malloc((num + 1) * sizeof(*page));
	if (!page)
		return (NULL);
	i = 0;
	j = -1;
	while (++j < num)
	{
		page[j] = ft_str(s, c, &i);
		if (!page[j])
		{
			free_page(page, j);
			return (NULL);
		}
	}
	page[j] = NULL;
	return (page);
}
