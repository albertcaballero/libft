/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:30:56 by alcaball          #+#    #+#             */
/*   Updated: 2023/12/02 11:28:18 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(int num, int cse, t_pf_buf* buf)
{
	unsigned int	unum;

	unum = (unsigned int) num;
	if (unum >= 16)
	{
		ft_puthex (unum / 16, cse, buf);
		unum = unum % 16;
	}
	if (unum <= 9)
		buf_add_char(unum + 48, buf);
	else if (unum > 9 && unum < 16 && cse == FT_PRINTF_UPPER)
		buf_add_char (unum + 55, buf);
	else if (unum > 9 && unum < 16 && cse == FT_PRINTF_LOWER)
		buf_add_char (unum + 87, buf);
}

void	ft_puthexadd(size_t num, int cse, t_pf_buf* buf)
{
	if (num >= 16)
	{
		ft_puthexadd(num / 16, cse, buf);
		ft_puthexadd(num % 16, cse, buf);
	}
	if (num <= 9)
		buf_add_char(num + 48, buf);
	else if (num > 9 && num < 16 && cse == FT_PRINTF_UPPER)
		buf_add_char (num + 55, buf);
	else if (num > 9 && num < 16 && cse == FT_PRINTF_LOWER)
		buf_add_char (num + 87, buf);
}

void	ft_put_add(size_t ad, t_pf_buf* buf)
{
	buffer_putstr("0x", buf);
	ft_puthexadd(ad, FT_PRINTF_LOWER, buf);
}
