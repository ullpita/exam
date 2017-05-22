/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 12:14:11 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/02/01 13:25:29 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	rostring(char *s)
{
	int i;
	int start;
	int end;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	start = i;
	while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\t')
		i++;
	end = i;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		if (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\t')
		{
			while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\t')
			{
				ft_putchar(s[i]);
				i++;
			}
			ft_putchar(' ');
		}
	}
	while (start < end)
	{
		ft_putchar(s[start]);
		start++;
	}
}

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac < 2)
		write(1, "\n", 1);
	else
	{
		i = 1;
		while (i < ac)
		{
			rostring(av[i]);
			i++;
			write(1, "\n", 1);
		}
	}
	return (0);
}


int		rostring(char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	j = i;
	while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
	{
		i++;
		k = i;
		if (str[i] == '\0')
		{
			write(1, &str[j], (k - j));
			return(0);
		}
	}
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\0')
	{
		if (str[i] != '\0')
			i++;
		if (str[i] == '\0')
		{
			write(1, &str[j], (k - j));
			return(0);
		}
	}
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
				i++;
			if (str[i])
				write(1, " ", 1);
		}
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			write(1, &str[i], 1);
		i++;
	}
	write(1, " ", 1);
	write(1, &str[j], (k - j));
	return(0);
}
