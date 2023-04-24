/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:00:37 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/24 17:07:11 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "libft_defines.h"
# include "libft_structs.h"

void			ft_btree_apply_infix(t_btree *root, void (*applyf)(void *));
void			ft_btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void			ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *));
t_btree			*ft_btree_create_node(void *item);
void			ft_btree_insert_data(t_btree **root, void *item, \
								int (*cmpf)(void *, void *));
void			*ft_btree_search_item(t_btree *root, void *data_ref, \
										int (*cmpf)(void *, void *));

int				ft_atoi(const char *nptr);
int				ft_btoi(const char *binary);
int				ft_htoi(const char *hexadecimal);
char			*ft_itoa(int n);
char			*ft_itob(int nbr);
char			*ft_itoh(int n);
char			*ft_itoo(int n);
int				ft_otoi(const char *octal);

int				ft_printf(const char *string, ...);
int				ft_printf_fd(int file_descriptor, const char *string, ...);
int				ft_printf_ln(const char *string, ...);

char			*get_next_line(int fd);

t_list			*ft_list_at(t_list *begin_list, size_t nbr);
t_list			*ft_list_find(t_list *begin_list, void *data_ref, \
								int (*cmp)(void *, void *));
void			ft_list_foreach_if(t_list *begin_list, void (*f)(void *), \
									void *data_ref, int (*cmp)(void *, void *));
t_list			*ft_list_push_strs(size_t size, char **strs);
void			ft_list_remove_if(t_list **begin_list, void *data_ref, \
									int (*cmp)(void *, void *), \
									void (*free_fct)(void *));
void			ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *));
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
							void (*del)(void *));
void			ft_lstmerge(t_list **begin_list1, t_list *begin_list2);
t_list			*ft_lstnew(void *content);
void			ft_lstreverse(t_list **begin_list);
size_t			ft_lstsize(t_list *lst);

unsigned int	ft_factorial(unsigned int n);
unsigned int	ft_next_prime(int nb);
double			ft_power(double number, int exponent);
unsigned int	ft_termial(unsigned int n);

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char *str);
void			ft_putstr_fd(char *s, int fd);

#endif
