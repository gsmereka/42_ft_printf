/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 04:54:14 by gsmereka          #+#    #+#             */
/*   Updated: 2022/07/15 00:00:48 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char	*ft_ptr_adr(char *word)
{
	char	*temp_w;

	temp_w = ft_alt_strdup(word);
	free(word);
	if (temp_w[0] == '0' && ft_strlen(temp_w) == 1)
		word = ft_alt_strdup("(nil)");
	else
	{
		word = ft_alt_strdup("0x");
		word = ft_alt_strjoin(word, temp_w);
	}
	free(temp_w);
	return (word);
}

static char	*ft_unsignedworks(const char *s, unsigned long long n)
{
	char	*word;
	int		i;

	i = 1;
	word = NULL;
	if (s[i] == 'x' || s[i] == 'X')
	{
		word = ft_itohex((unsigned int)n);
		if (s[i] == 'X')
		{
			i = 0;
			while (word[i++])
				word[i - 1] = ft_toupper(word[i - 1]);
		}
	}
	else if (s[i] == 'p')
	{
		word = ft_itohex(n);
		word = ft_ptr_adr(word);
	}
	else if (s[i] == 'u')
		word = ft_utoa((unsigned int)n);
	return (word);
}

static char	*ft_atow(const char *s, va_list args)
{
	int		i;
	char	*word;

	i = 1;
	if (s[i] == 'c' || s[i] == '%')
		word = ft_alt_strdup("");
	if (s[i] == 'c')
		word = ft_addchar(word, va_arg(args, int));
	if (s[i] == '%')
		word = ft_addchar(word, '%');
	if (s[i] == 's')
	{
		word = NULL;
		word = va_arg(args, char *);
		if (!word)
			word = ft_strdup("(null)");
		else
			word = ft_strdup(word);
		return (word);
	}
	if (s[i] == 'd' || s[i] == 'i')
		word = ft_itoa(va_arg(args, int));
	if (s[i] == 'x' || s[i] == 'X' || s[i] == 'p' || s[i] == 'u')
		word = ft_unsignedworks(s, va_arg(args, unsigned long long));
	return (word);
}

static int	ft_printsizefree(char *final_str)
{
	int	size;

	ft_putstr_fd(final_str, 0);
	size = ft_strlen(final_str);
	free(final_str);
	return (size);
}

int	ft_printf(const char *s, ...)
{
	printf("cheguei\n");
	va_list	args;
	char	*final_str;
	char	*word;
	int		i;

	i = 0;
	va_start(args, s);
	final_str = ft_strdup("");
	while (s[i])
	{
		if (s[i] == '%')
		{
			word = ft_atow(&s[i], args);
			final_str = ft_alt_strjoin(final_str, word);
			free(word);
			i++;
		}
		else
			final_str = ft_addchar(final_str, s[i]);
		i++;
	}
	va_end(args);
	i = ft_printsizefree(final_str);
	return (i);
}
