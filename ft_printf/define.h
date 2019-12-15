/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:55:16 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/04 15:55:17 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define NUMBER_DOUBLE		tab->u_double.input_double
# define MANTISSA			tab->u_double.s_d_parts.mantissa
# define EXPONENT			tab->u_double.s_d_parts.exponent
# define SIGN				tab->u_double.s_d_parts.sign

# define NUMBER_LD			tab->u_ld.input_long_double
# define MANTISSA_L			tab->u_ld.s_ld_parts.mantissa
# define EXPONENT_L			tab->u_ld.s_ld_parts.exponent
# define SIGN_L				tab->u_ld.s_ld_parts.sign
# define INTEGER			tab->u_ld.s_ld_parts.integer

# define PART_INT			tab->s_init_str_f.part_int
# define PART_FLOAT			tab->s_init_str_f.part_float
# define STR_RET			tab->s_init_str_f.string_return
# define LEN_PI				tab->s_init_str_f.len_part_int
# define LEN_PF				tab->s_init_str_f.len_part_float
# define LEN_STRING_RETURN	tab->s_init_str_f.len_string_return
# define POS_POINT			tab->s_init_str_f.pos_point

# define F_HASH				tab->input_flag[0]
# define F_0				tab->input_flag[1]
# define F_NEG				tab->input_flag[2]
# define F_PLUS				tab->input_flag[3]
# define F_SPACE			tab->input_flag[4]
# define PRECISION			tab->precision
# define DIGIT				tab->digit
# define CSPDIOUXXF			tab->input_flag_cspdiouxxf
# define RET_LEN			tab->return_len
# define BIAS_D				tab->bias_double
# define BIAS_LD			tab->bias_long_double
# define I_LD				tab->x
# define I_ZP				tab->index_zero_point
# define I_I                tab->inter_index
# define MAX_L				9223372036854775807

# define LEN                tab->s_hex_integer.len
# define LEN_STR            tab->s_hex_integer.len_str
# define CALC               tab->s_hex_integer.calc
# define CALC_2             tab->s_hex_integer.calc_2
# define ZERO               tab->s_hex_integer.zero

# define LEN_F				tab->len
# define UPD_LEN			tab->update_len
# define INDEX				tab->index

# define I					tab->arr[0]
# define J					tab->arr[1]
# define K					tab->arr[2]
# define I_CALC				tab->arr[3]
# define RET				tab->arr[4]

# define I_ADD				tab->s_str_add.i
# define J_ADD				tab->s_str_add.j
# define K_ADD				tab->s_str_add.k
# define STR_ADD			tab->s_str_add.str
#endif
