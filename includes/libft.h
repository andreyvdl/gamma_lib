/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:00:37 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/13 13:33:27 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*content;
}	t_btree;

// linked list
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(void *content);
void			ft_lstreverse(t_list **begin_list);
t_list			*ft_lstpush_strs(int size, char **strs);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void			ft_lstsort(t_list **begin_list, int (*cmp)());
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
t_list			*ft_lstat(t_list *begin_list, unsigned int nbr);
void			ft_lstremove_if(t_list **begin_list, void *data_ref,
					int (*cmp)(), void (*free_fct)(void *));
void			ft_lstmerge(t_list **begin_list1, t_list *begin_list2);
void			ft_lst_foreach_if(t_list *begin_list, void (*f)(void *),
					void *data_ref, int (*cmp)());
t_list			*ft_lstfind(t_list *begin_list, void *data_ref, int (*cmp)());

// binary tree
t_btree			*ft_betree_new(void *item);
void			ft_btree_insert_data(t_btree **root, void *item,
					int (*cmpf)(void *, void*));
void			*ft_btree_search_item(t_btree *root, void *data_ref,
					int (*cmpf)(void *, void *));
void			ft_btree_apply_infix(t_btree *root, void (*applyf)(void *));
void			ft_btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void			ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *));

// check things & returns true or false
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isupper(int c);
int				ft_isprime(long long int nb);

int				ft_tolower(int c);
int				ft_toupper(int c);

// work with memory
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

// work with strings
char			*ft_itoa(int n);
char			*ft_strupcase(char *str);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strlowcase(char *str);
int				ft_atoi(const char *nptr);
char			*ft_strcapitalize(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dst, char *src);
char			*ft_strchr(const char *s, int c);
char			**ft_split(char const *s, char c);
char			*ft_strcat(char *dest, char *src);
char			*ft_strrchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strstr(const char *str, const char *to_find);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strnstr(const char *big, const char *little, size_t len);

// print & file descriptors
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);

// work with pointers
void			ft_swap(void **a, void **b);

// mathemathics
long double		ft_sqrt(long double n);
long long int	ft_fact(long long int n);
long long int	ft_next_prime(long long int nb);

#endif