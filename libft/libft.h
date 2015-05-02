/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 21:47:15 by gleger            #+#    #+#             */
/*   Updated: 2015/03/05 11:03:20 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <string.h>

# define BUFF_SIZE 64

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_data
{
	void			*data;
	int				index;
	struct s_data	*next;
	struct s_data	*prev;
}					t_data;

typedef struct		s_c
{
	char			c;
	int				(*f)(va_list ap, int nb);
}					t_c;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strdel2(char ***array);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *s1, char *s2, int opt);
char				*ft_str_multi_join(int ac, ...);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strrev(char *str);

int					ft_atoi(const char *str);
char				*ft_itoa(int n);
int					ft_abs(int n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_sqrt(int nb);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int nb);
int					ft_putnbr_base(long nb, const char *base);
int					ft_putnbr_base_u(unsigned int nb, const char *base);
int					ft_putnbr_pf(va_list ap, int nbb);
int					ft_putnbr_u_pf(va_list ap, int nbb);
int					ft_putchar_pf(va_list ap, int nbb);
int					ft_putz_pf(va_list ap, int nbb);
int					ft_putstr_pf(va_list ap, int nbb);
int					ft_putoctal_pf(va_list ap, int nbb);
int					ft_puthexa_pf(va_list ap, int nbb);
int					ft_puthexa_min_pf(va_list ap, int nbb);
int					ft_puthexa_max_pf(va_list ap, int nbb);
int					ft_return_nb_nb(long nb, const char *base);
int					ft_return_nb_nb_di(int nb, const char *base);
int					ft_printf(const char *format, ...);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstlen(t_list *dp);
t_list				*ft_lstrev(t_list *dp);

t_data				*create_list(void);
void				add_forward(t_data *elem, void *data);
void				add_backward(t_data *elem, void *data);
void				add_head(t_data *root, void *data);
void				add_tail(t_data *root, void *data);
void				del_elem(t_data *elem);
void				del_first_elem(t_data *root);
void				del_last_elem(t_data *root);
void				empty_list(t_data *root);
void				del_list(t_data **root);
void				display_list(t_data *tmp);
t_data				*fill_list(int argc, char **argv);

int					get_next_line(int const fd, char **line);
void				ft_swap(int *a, int *b);
void				ft_swap_double(double *a, double *b);
int					ft_isdigit_char(char c);
int					ft_isdigit_str(char *str);
double				ft_atoi_double(const char *str);
int					ft_check_if_int(char *nbr);
char				**ft_rea_scd_array(char **src, int add);

#endif
