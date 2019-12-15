/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:19:29 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/09 13:23:23 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*no_zero(t_tab *tab, char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (str[i] == '0')
		i++;
	tab->tmp_2 = ft_strsub(str, i, len);
	return (tab->tmp_2);
}

char	*str_zero(int n)
{
	char	*str;
	int		i;

	i = -1;
	str = ft_strnew(n + 1);
	str[n] = '\0';
	while (++i < n)
		str[i] = '0';
	return (str);
}

char	*power(t_tab *tab, int nb, int i)
{
	char	*str;
	char	*s;
	char	*rslt;
	char	*tmp;

	rslt = ft_itoa(nb);
	while (i != 1)
	{
		s = ft_itoa(nb);
		tmp = rslt;
		rslt = string_multi(tab, rslt, s);
		ft_strdel(&tmp);
		i--;
		ft_strdel(&s);
	}
	str = no_zero(tab, rslt);
	ft_strdel(&rslt);
	return (str);
}

char	*join(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		len_s1;
	int		len_s2;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (s1 != NULL)
		i = i + len_s1;
	if (s2 != NULL)
		i = i + len_s2;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	str = ft_strnew(i + 1);
	ft_bzero(str, (i + 1));
	if (s1 != NULL)
		ft_strcpy(str, s1);
	if (s2 != NULL)
		ft_strcpy(&str[len_s1], s2);
	str[i] = '\0';
	free_str(s1, s2, NULL);
	return (str);
}

void	free_str(char *a, char *b, char *c)
{
	ft_strdel(&a);
	ft_strdel(&b);
	ft_strdel(&c);
}
