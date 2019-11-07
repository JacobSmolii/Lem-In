/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:10:41 by vsmolii           #+#    #+#             */
/*   Updated: 2019/07/18 20:31:25 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

/*
** get_next_line libs below
*/

# define BUFF_SIZE 32
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

/*
** printf libs below
*/

# include <stdarg.h>
# include <wchar.h>

/*
** libft structure below
*/

typedef struct	s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}				t_list;

/*
** get_next_line structure below
*/

typedef struct	s_line
{
	char				*str;
	int					fd;
	struct s_line		*next;
}				t_line;

/*
** printf structure below
*/

typedef struct	s_format
{
	int			p;
	int			ms;
	int			h;
	int			sp;
	int			z;
	int			ch;
	int			ch_cap_x;
	int			x_cap_x;
	int			w;
	int			prs;
	int			prs_ext;
	char		*len;
}				t_format;

int				ft_factorial(int n);
int				ft_fibonacci(int n);
int				ft_max(int *tab, unsigned int len);
int				ft_power2(int a, int n);
void			ft_swap(int *a, int *b);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *restrict dst, const void *restrict src,
					size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *str, int x, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putstr(char const *s);
char			*ft_strcat(char *restrict s1, const char *restrict s2);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *restrict s1, char *restrict s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t len);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *big, const char *little, size_t l);
char			*ft_strrchr(const char *s, int c);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
int				ft_tolower(int c);
int				ft_toupper(int c);

/*
** get_next_line functions below
*/

int				get_next_line(const int fd, char **line);
int				reading(int fd, char **line, t_line **head);
void			get_tail(const int fd, char *buf, t_line **head);
int				len(char *s, int c);

/*
** printf functions below
*/

int				ft_printf(char *str, ...);
int				ft_output_hope(int *i, va_list arg, char *str);
void			ft_parsing(t_format *data, char *str, int *i);
char			*ft_itoa_intmax(long long value);
char			*itoa_fill_un(char *str, uintmax_t value, int base);
char			*itoa_fill_unsigned(uintmax_t value, int base);
char			*ft_itoa_unsigned(uintmax_t value);
char			*ft_itoa_base_unsigned(uintmax_t value, int base);
char			*itoa_filler_b(char *str, uintmax_t value, int base);
char			*ft_itoa_base(intmax_t value, int base);
char			*ft_itoa_base_ll(long long int n, char *base);
char			*itoa_filler_p(char *tab, intmax_t val, int base, int flag);
intmax_t		ft_abs(intmax_t nb);
char			*itoa_filler(char *str, uintmax_t value);
long long		ft_sign(long long nbr);
char			*itoa_fill(char *str, long long value, int flag);
char			*ft_update(char *str, char *update);
void			init_data(t_format *data);
int				get_flags(t_format *data, char *str, int i);
int				get_width(t_format *data, char *str, int i);
int				get_precision(t_format *data, char *str, int i);
int				get_length_flag(t_format *data, char *str, int i);
char			*str_space(char *s_width, int len);
int				start_o_work(va_list arg, t_format *data,
								char *str, int *i);
char			*work_with_o_format(t_format *data, uintmax_t nbr);
char			*get_precs_o_str(t_format *data, char *str,
								int len_str, uintmax_t nbr);
char			*get_width_o_str(t_format *data, char *str);
char			*ft_toupper_str(char *str);
int				start_p_work(va_list arg, t_format *data);
int				work_woth_c_format(va_list arg, t_format *data);
int				start_d_work(va_list arg, t_format *data);
char			*work_with_d_format(t_format *data, intmax_t nbr);
char			*get_precision_str(t_format *data, char *str,
								int len_str, intmax_t nbr);
char			*get_width_str(t_format *data, char *str, intmax_t nbr);
char			*flag_plus_or_space(char *str, char symb);
char			*str_fill(int len, char symb);
char			*precis_str_fill(t_format *data, char *str,
								int len_str, intmax_t nbr);
int				work_with_s_format(va_list arg, t_format *data);
char			*get_precision_new_str(t_format *data, char *str,
								int len_str);
char			*get_width_new_str(t_format *data, char *str);
char			*convert_float_nbr(t_format *data, long double nbr);
int				convers_f(va_list arg, t_format *data);
char			*get_width_f_str(t_format *data, char *str, int len,
														long double nbr);
char			*change_symb_position(char *str, char symb);
int				start_persnt_work(t_format *data);
char			*get_width_str_2(t_format *data, char *str, intmax_t nbr);
char			*get_width_f_str_2(t_format *data, char *str, int len);
char			*persent_work_2(t_format *data, int len);
char			*extra_func_c_1(char *str, int len);
char			*extra_func_c_2(t_format *data, int len, char *str, char c);
void			extra_func_o(t_format *data, char *str, int *i);
char			*extra_func_d(t_format *data, char *str, int len_new);
char			*get_precs_f(t_format *d, char *str, int sign,
														long double nbr);
void			prepare_float(int *sign, long double *nbr, t_format *data);
int				start_f_work(va_list arg, t_format *data);

#endif
