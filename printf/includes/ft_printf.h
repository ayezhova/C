/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayezhova <ayezhova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:24:10 by ayezhova          #+#    #+#             */
/*   Updated: 2020/02/04 13:07:37 by ayezhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "../libft/libft.h"

typedef struct	s_arg_flags
{
	int		conversion_flags[5];
	int		field_width;
	int		precision;
	char	alt_coversion_specifier;
	char	conversion_specifier;
}				t_flags;

int				ft_printf(char *str, ...);
int				check_field_width(char *str, t_flags *flags, int i,
		va_list arg_list);
int				check_cover_flags(char *str, t_flags *flags, int i);
int				check_precision(char *str, t_flags *flags, int i,
		va_list arg_list);
int				check_alt_specifier(char *str, t_flags *flags, int i);
int				handle_simple_conversion(char c, va_list args, int *len);
void			handle_simple_oct(va_list args, int *len_total);
void			handle_simple_hex(va_list args, char c, int *len_total);
void			handle_simple_point(va_list args, int *len_total);
void			handle_simple_float(va_list args, int *len_total);
int				find_specifier(char *str, t_flags *flags, int i);
void			print_char(char c, int n);
void			handle_dif_int(va_list arg_list, t_flags *flags, int *len);
void			handle_dif_char(va_list arg_list, t_flags *flags, int *len);
void			handle_dif_unsigned(va_list arg_list, t_flags *flags,
		int *len);
void			handle_dif_str(va_list args, t_flags *flags, int *len_total);
void			handle_dif_float(va_list args, t_flags *flags,
		int *len_total);
void			handle_dif_percent(t_flags *flags, int *len);
void			handle_dif_point(va_list args, t_flags *flags, int *len);
void			dif_unsigned_base(uintmax_t ret, t_flags *flags, int *len);
void			ft_putnbr_u(uintmax_t n, int digits);
void			write_sign_u(t_flags *flags, uintmax_t *value);
int				alt_num_u(t_flags *flags, int *sign, uintmax_t ret);
void			get_zeros_u(t_flags *flags, int *zeros, int *spaces,
		int digits);
void			check_if_digits_zero(int *digits, int ret, t_flags *f);
char			*ft_ftoa(long double num, int lengths[2], int neg,
		int precision);
void			set_int_zero(int *int_len, char *str, int *i);
void			handle_num_printed(va_list args, int *len_total);
void			handle_m(va_list args, int *len_total);

#endif
