/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:03:03 by smontuor          #+#    #+#             */
/*   Updated: 2024/01/25 16:44:30 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>

# ifndef FD_MAX
#  define FD_MAX 4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/******************************************************************************/
/*                     Functions inside /ctype                                */
/******************************************************************************/
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
/******************************************************************************/
/*                     Functions inside /string                               */
/******************************************************************************/
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strtrim(char const *s1, char const *set);
/******************************************************************************/
/*                     Functions inside /stdlib                               */
/******************************************************************************/
int				ft_atoi(const char *nptr, int *error);
void			*ft_calloc(size_t nmemb, size_t size);
/******************************************************************************/
/*                     Functions inside /not_standard                         */
/******************************************************************************/
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_uitoa(unsigned int n);
int				ft_issign(int c);
void			ft_free_matrix(char **matrix);
int				ft_free_arrays(void **ar1, void **ar2, void **ar3);
void			ft_exit_error(char *msg);
int				ft_open_file(const char *file);
/******************************************************************************/
/*                     Functions inside /list                                 */
/******************************************************************************/
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void*));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
/******************************************************************************/
/*                     Functions inside /gnl                                  */
/******************************************************************************/
char			*ft_get_next_line(int fd);
int				ft_get_all_lines(const char *file, char ***all_lines);
/******************************************************************************/
/*                     Functions inside /mem                                  */
/******************************************************************************/
void			ft_bzero(void *s, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
/******************************************************************************/
/*                     Functions inside /ft_fd                                */
/******************************************************************************/
int				ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
int				ft_putnbr_fd(int n, int fd);
ssize_t			ft_putstr_fd(char *s, int fd);
int				ft_putunsigned_fd(unsigned int n, int fd);
int				ft_putptr_fd(uintptr_t ptr, int fd);
int				ft_puthex_fd(unsigned int num, char format, int fd);
int				ft_putnbrbase_wrapper_fd(uintptr_t nbr, char *base, int fd);
int				ft_printf(int fd, const char *format, ...);
int				ft_isspace(int c);
/******************************************************************************/
/*                     Functions inside /ft_printf                            */
/******************************************************************************/
int				ft_printf(int fd, const char *format, ...);

#endif
