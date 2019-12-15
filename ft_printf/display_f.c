/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 23:32:36 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/10 23:32:37 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_f_2(t_tab *tab, char *final_string)
{
	if (DIGIT > 2147483647)
		DIGIT = 0;
	if (!ft_isalpha(final_string[1]))
	{
		LEN_F = ft_strlen(final_string);
		RET_LEN += LEN_F;
		UPD_LEN = display_f_3(tab, LEN_F, UPD_LEN, final_string);
		if (tab->k == 1 && (RET_LEN++))
			write(1, "1", 1);
		if (PRECISION == 0 && tab->y != 1)
		{
			while (INDEX < LEN_PF - 1)
				write(1, &final_string[INDEX++], 1);
			if (LEN_PF == 1 && (RET_LEN++))
				write(1, &final_string[0], 1);
			RET_LEN--;
		}
		else
			ft_printf("%s", final_string);
		display_f_4(tab, UPD_LEN, LEN_F);
	}
	else
		display_inf_nan(tab, final_string);
}

int		display_f_3(t_tab *tab, int len, int update_len, char *final_string)
{
	int index;

	index = 0;
	if (SIGN == 1)
		len++;
	if (DIGIT != 0)
		update_len = DIGIT - len;
	if (F_PLUS == '+' && SIGN == 0)
		update_len--;
	if (tab->k && PRECISION > 0)
		update_len--;
	if (!F_NEG && !F_SPACE && !F_0 && DIGIT > len)
		display_space_zero(tab, ' ', update_len, 1);
	if (F_SPACE && SIGN == 0 && (index = 1) && !F_PLUS && !I_LD)
		display_space_zero(tab, ' ', 1, 1);
	if (index == 1)
		update_len -= 1;
	if (F_SPACE && SIGN_L == 0 && (index = 1) && !F_PLUS && I_LD)
		display_space_zero(tab, ' ', 1, 1);
	if (F_SPACE && DIGIT && F_0 != '0' && F_NEG != '-')
		display_space_zero(tab, ' ', update_len, 1);
	dispay_f_5(tab, update_len, final_string);
	return (update_len);
}

void	dispay_f_5(t_tab *tab, int update_len, char *final_string)
{
	if (!I_LD && F_PLUS == '+' && SIGN == 0)
		display_sign(tab, 1, final_string);
	if (!I_LD && SIGN == 1)
		display_sign(tab, 2, final_string);
	if (I_LD && F_PLUS == '+' && SIGN_L == 0)
		display_sign(tab, 1, final_string);
	if (I_LD && SIGN_L == 1)
		display_sign(tab, 2, final_string);
	if (F_0 && F_NEG != '-' && DIGIT > PRECISION)
	{
		if (ft_isalpha(final_string[1]))
			display_space_zero(tab, ' ', update_len, 1);
		else
			display_space_zero(tab, '0', update_len, 1);
	}
}

void	display_f_4(t_tab *tab, int update_len, int len)
{
	if (F_NEG)
		display_space_zero(tab, ' ', update_len, 1);
	if (F_HASH && PRECISION == 0 && (RET_LEN++))
		write(1, ".", 1);
	if (PRECISION > 51)
		display_space_zero(tab, '0', PRECISION - len + LEN_PF, 1);
}
