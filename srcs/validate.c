/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 22:16:38 by amyburgh          #+#    #+#             */
/*   Updated: 2018/05/24 15:51:33 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		validate_shift(char *buf)
{
	int i;
	int shift;

	i = -1;
	shift = 0;
	while (++i < 20)
	{
		if (buf[i] == '#')
		{
			(buf[i + 1] == '#' && i % 5 < 3) ? shift++ : shift;
			(buf[i - 1] == '#' && i % 5 > 0) ? shift++ : shift;
			(buf[i + 5] == '#' && i / 5 < 3) ? shift++ : shift;
			(buf[i - 5] == '#' && i / 5 > 0) ? shift++ : shift;
		}
	}
	if (shift != 6 && shift != 8)
		return (1);
	return (0);
}

int		validate_block(char *buf, int bytes)
{
	int	i;
	int	hash_count;

	i = -1;
	hash_count = 0;
	while (++i < 20)
	{
		if (i % 5 < 4)
		{
			if (buf[i] != '#' && buf[i] != '.')
				return (1);
			if (buf[i] == '#' && ++hash_count > 4)
				return (1);
		}
		else if (buf[i] != '\n')
			return (1);
	}
	if (bytes == 21 && buf[20] != '\n')
		return (1);
	if (validate_shift(buf))
		return (1);
	return (0);
}
