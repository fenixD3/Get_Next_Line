/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:04:30 by ylila             #+#    #+#             */
/*   Updated: 2019/04/10 15:07:15 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	make_result(const char *str, _Bool sign)
{
	long long res;
	long long max;

	res = 0;
	max = 9223372036854775807;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			if ((sign && (res <= ((max - (*str - '0')) / 10))) ||
			(!sign && (-res >= ((-max - 1 + (*str - '0')) / 10))))
				res = res * 10 + (*str - '0');
			else if (sign)
				return (-1);
			else if (!sign)
				return (0);
		}
		else
			break ;
		++str;
	}
	if (sign == 0)
		res = -res;
	return ((int)res);
}

int			ft_atoi(const char *str)
{
	_Bool is_negative;

	is_negative = 1;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' ||
	*str == '\r' || *str == '\f' || *str == '\v'))
		++str;
	if (*str == '-')
	{
		is_negative = 0;
		++str;
	}
	else if (*str == '+')
	{
		is_negative = 1;
		++str;
	}
	return (make_result(str, is_negative));
}
