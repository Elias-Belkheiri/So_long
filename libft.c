/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:53:33 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/01/03 11:56:14 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_putnb(long nb, char *p, int *i)
{
	int	idx;

	idx = *i;
	if (nb < 0)
	{
		p[idx] = '-';
		nb *= -1;
		idx++;
		*i = idx;
	}
	if (nb <= 9)
	{
		p[idx] = nb + '0';
		idx++;
		*i = idx;
	}
	else if (nb > 9)
	{
		ft_putnb(nb / 10, p, i);
		ft_putnb(nb % 10, p, i);
	}
}

char	*ft_itoa(int n)
{
	int		num;
	int		i;
	int		sign;
	char	*p;

	num = n;
	i = 0;
	sign = 0;
	if (n < 0 || !n)
		sign = 1;
	while (num)
	{
		num /= 10;
		i++;
	}
	p = malloc(i + sign + 1);
	if (!p)
		return (NULL);
	i = 0;
	ft_putnb(n, p, &i);
	p[i] = '\0';
	return (p);
}

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)src;
	if (!dstsize)
		return (ft_strlen(s));
	if (dstsize <= 0)
		dstsize = ft_strlen(s) + 1;
	while (dstsize-- > 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(s));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*dup;

	str = (char *)s;
	if (!str)
		return (NULL);
	if (start > ft_strlen(str))
		return (ft_strdup(""));
	if (len > ft_strlen(str + start))
	{
		dup = malloc(ft_strlen(str + start) + 1);
		len = ft_strlen(str + start);
	}
	else
		dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, str + start, len + 1);
	return (dup);
}

void	ft_free_all_mfs(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
