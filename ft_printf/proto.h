/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:16:51 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/10 23:24:58 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

t_tab		*display_float(t_tab *tab);
char		*mantisa_calc(t_tab *tab);
int			check_type(t_tab *tab);

t_tab		*case_long_double(t_tab *tab);
char		*mantissa_long_double(t_tab *tab);
void		init_str_f_3(t_tab *tab, char *final_string);

t_tab		*display_char(t_tab *tab);

t_tab		*display_decimal(t_tab *tab);
t_tab		*display_d(t_tab *tab, intmax_t num, int len);
char		get_input_flag(t_tab *tab, int is_sign);

void		display_f_2(t_tab *tab, char *final_string);
void		case_mantissa_zero(t_tab *tab);
void		display_sign(t_tab *tab, int i, char *str);
void		display_inf_nan(t_tab *tab, char *str);

t_tab		*display_hex_integer(t_tab *tab);
t_tab		*display_x(t_tab *tab, uintmax_t num, char *str, int index);

t_tab		*display_octal_integer(t_tab *tab);
t_tab		*display_o(t_tab *tab, uintmax_t num, char *str);

t_tab		*display_pointer_hex(t_tab *tab);

t_tab		*display_string(t_tab *tab);

t_tab		*display_u_decimal(t_tab *tab);
t_tab		*display_u(t_tab *tab, uintmax_t num, int len);

int			ft_printf(const char *format, ...);
int			parse_init(t_tab *tab);

int			check_inf_nan(t_tab *tab);
void		binary(int n, int i, char str[]);

t_tab		*init(t_tab *tab);
t_tab		*re_init(t_tab *tab);
int			init_function(t_tab *tab);
t_tab		*display(t_tab *tab);

void		init_str_f(t_tab *tab, char *final_string);
char		*case_zero_point_2(t_tab *tab, char *final_string);
char		*test(t_tab *tab, char *str);
char		*increase_float_2(t_tab *tab, char *str, int len);
int			tt(t_tab *tab, int len);

char		*ft_strndup(const char *s1, size_t n);
char		*ft_strndup_r(const char *s1, size_t n, int move);
char		*ft_itoa_base(uintmax_t num, uintmax_t base, char c);
char		ft_calculate_char(int mod, char c);
int			ft_get_len(uintmax_t num, uintmax_t base);

char		*string_multi(t_tab *tab, char *s1, char *s2);
char		*string_add(t_tab *tab, char *s1, char *s2);

t_tab		*other_display(t_tab *tab);
t_tab		*display_percent(t_tab *tab);

t_tab		*parse_flag(t_tab *tab);
t_tab		*parse_digit(t_tab *tab);
t_tab		*parse_precision(t_tab *tab);
t_tab		*parse_flag_llh(t_tab *tab);
t_tab		*parse_flag_cspdiouxxf(t_tab *tab);

char		*no_zero(t_tab *tab, char *str);
char		*str_zero(int n);
char		*power(t_tab *tab, int nb, int i);
char		*join(char *s1, char *s2);
char		*ft_strrev(char *str);

int			strlen_digit(intmax_t num);
void		display_0x(uintmax_t num, char hash, char x);
void		display_space_zero(t_tab *tab, char c, int len, int update_len);
void		ft_putnbrmax(intmax_t n);
void		ft_putnbrumax(uintmax_t n);

intmax_t	type_decimal(t_tab *tab);
uintmax_t	type_octal_integer(t_tab *tab);
uintmax_t	type_hex_integer(t_tab *tab);
uintmax_t	type_u_decimal(t_tab *tab);
long double	get_type_float(t_tab *tab);

int			strlen_digit_u(uintmax_t num);
void		display_decimal_2(t_tab *tab);
char		*integer_case(t_tab *tab);
int			display_f_3(t_tab *tab, int len, int update_len, char *str);
void		display_x_2(t_tab *tab, uintmax_t num, char *str);
void		display_f_4(t_tab *tab, int update_len, int len);
void		dispay_f_5(t_tab *tab, int update_len, char *final_string);
char		*increase_float_3(t_tab *tab, char *str, char *cpy, int len);
char		*increase_float_4(t_tab *tab, char *str, char *cpy, int len);
char		*increase_float_5(t_tab *tab, char *str, char *cpy, int len);
void		string_add_2(t_tab *tab, char *s1);
void		free_str(char *a, char *b, char *c);
void		free_string(t_tab *tab);
int			mantissa_calc_2(t_tab *tab);
int			mantissa_long_double_2(t_tab *tab);
void		init_str_f_4(t_tab *tab);
#endif
