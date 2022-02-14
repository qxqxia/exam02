/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:46:01 by qxia              #+#    #+#             */
/*   Updated: 2022/02/07 17:57:16 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//判断是否有重复
//先判断s1 再判断s2  s2里面再判断有没有跟s1相同的 然后打印

#include <unistd.h>

int	ft_check_char(char *str, char c, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_union(char *s1, char *s2)
{
	int	i;
	int	len;

	i = 0;
	while (s1[i])
	{
		if (ft_check_char(s1, s1[i], i) == 1)
			write (1, &s1[i], 1);
		i++;
	}
	len = i;
	i = 0;
	while (s2[i])
	{
		if (ft_check_char(s2, s2[i], i) == 1)
		{
			if (ft_check_char(s1, s2[i], len) == 1)
				write (1, &s2[i], 1);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}


