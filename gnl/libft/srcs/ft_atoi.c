/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:15:17 by afrantzi          #+#    #+#             */
/*   Updated: 2018/04/22 11:41:50 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	crunch(const char *str, int num, int i)
{
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num);
}

int			ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	neg;

	neg = 1;
	num = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 45 || str[i] == 43)
		{
			if (str[i] == 45)
				neg = -1;
			i++;
			if (str[i] < 48 || str[i] > 57)
				return (0);
		}
		else if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else if (str[i] >= 48 && str[i] <= 57)
			return (crunch(str, num, i) * neg);
		else
			return (0);
	}
	return (num * neg);
}
