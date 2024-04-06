/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:00:37 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/06 01:28:30 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>

/* ================================ Defines ================================ */

// GNL buffer size, it reads 4096 bytes (4Kb)
# define BUFFER_SIZE 4096


// Redefinition of NULL
# define NIL 0x0

// A magic number for the ft_rand function
# define LCG_MULTIPLIER 6364136223846793005U

/* ================================= Types ================================= */

/**
 * @brief Liked list struct
 * 
 * @param content The pointer to the content of the node
 * @param next The pointer to the next node
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @brief Binary tree struct
 * 
 * @param content The pointer to the content of the node
 * @param left The pointer to the left node
 * @param right The pointer to the right node
 */
typedef struct s_btree
{
	void			*content;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;


/* =============================== Functions =============================== */
/* ------------------------------ Binary tree ------------------------------ */

// Creates a new node of the binary tree;
t_btree		*ft_btree_create_node(void *item);
// Call a function that apply a fix after going through all left nodes;
void		ft_btree_apply_infix(t_btree *root, void (*applyf)(void *));
// Call a function to apply a fix before going to the next node;
void		ft_btree_apply_prefix(t_btree *root, void (*applyf)(void *));
// Call a function to apply a fix after going through all nodes;
void		ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *));
// Insert a node in the binary tree based on the cmpf;
void		ft_btree_insert_data(t_btree **root, void *item, \
	int (*cmpf)(void *, void *));
// Search an item in the binary tree;
void		*ft_btree_search_item(t_btree *root, void *data_ref, \
	int (*cmpf)(void *, void *));

/* ------------------------------ Linked list ------------------------------ */

t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
t_list		*ft_list_at(t_list *begin_list, size_t nbr);
t_list		*ft_list_push_strs(size_t size, char **strs);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_list_find(t_list *begin_list, void *data_ref,
	int (*cmp)(void *, void *));
size_t		ft_lstsize(t_list *lst);
void		ft_lstreverse(t_list **begin_list);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstmerge(t_list **begin_list1, t_list *begin_list2);
void		ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *));
void		ft_list_remove_if(t_list **begin_list, void *data_ref,
	int (*cmp)(void *, void *), void (*free_fct)(void *));
void		ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
	void *data_ref, int (*cmp)(void *, void *));

/* ---------------------------- Composed return ---------------------------- */

uint32_t	ft_next_prime(int nb);
uint32_t	ft_termial(uint32_t n);
uint32_t	ft_factorial(uint32_t n);

// Checks for an alphanumeric character;
bool		ft_isalnum(int c);
// Checks for an alphabetic character;
bool		ft_isalpha(int c);
// Checks for an ASCII character;
bool		ft_isascii(int c);
// Checks for space or tab;
bool		ft_isblank(int c);
// Checks for a digit;
bool		ft_isdigit(int c);
// Checks for a lowercase character;
bool		ft_islower(int c);
// Checks for any printable character including space;
bool		ft_isprint(int c);
// Checks for any whitespace character;
bool		ft_isspace(int c);
// Checks for an uppercase letter;
bool		ft_isupper(int c);
// Checks for hexadecimal digits;
bool		ft_isxdigit(int c);
// Checks if the number is prime;
bool		ft_isprime(int nb);
size_t		ft_strlen(char *s);
size_t		ft_rand(size_t seed, size_t min, size_t max);
size_t		ft_strspn(char *s, char *accept);
size_t		ft_strcspn(char *s, char *reject);
size_t		ft_strlcat(char *dst, char *src, size_t size);
size_t		ft_strlcpy(char *dst, char *src, size_t size);

/* -------------------------- Comum pointer return -------------------------- */

/**
 * @brief Converts an integer to a string;
 * 
 * @param n The integer to be converted;
 * @return NULL if the allocation fails, otherwise the string (char *);
 */
char *		ft_itoa(int n);

/**
 * @brief Converts an integer to a hexadecimal string;
 * 
 * @param n The integer to be converted;
 * @return NULL if allocation fails or if n is negative, otherwise the string
 * 			(char *);
 */
char *		ft_itoh(int n);

/**
 * @brief Converts an integer to octal
 * 
 * @param n The integer to be converted
 * @return NULL if the integer is negative; Otherwise, the converted number
 * 			in octal (char *);
 */
char *		ft_itoo(int n);

/**
 * @brief Converts an integer to a binary string;
 * 
 * @attention The size of the string is based from the MSB of the integer;
 *
 * @param nbr the integer to be converted;
 * @return NULL if the allocation fails or if nbr is negative, otherwise the
 * 			string (char *);
 */
char		*ft_itob(int nbr);
char		*ft_strrev(char *str);
char		*get_next_line(int fd);
char		*ft_strupcase(char *str);
char		*ft_strdup(char *s);
char		*ft_strlowcase(char *str);
char		*ft_strcapitalize(char *str);
char		**ft_matrixdup(char **matrix);
char		*ft_strchr(char *s, int c);
char		*ft_strcpy(char *dst, char *src);
char		**ft_split(char *s, char c);
char		*ft_strcat(char *dest, char *src);
char		*ft_strrchr(char * s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strtrim(char *s1, char *set);
char		*ft_strpbrk(char *s, char *accept);
char		*ft_strstr(char *str, char *to_find);
char		*ft_substr(char *s, uint32_t start, size_t len);
char		*ft_strmapi(char *s, char (*f)(uint32_t, char));
char		*ft_strnstr(char *big, char *little, size_t len);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(void *s, int c, size_t n);
void		*ft_memcpy(void *dst, void *src, size_t n);
void		*ft_memmove(void *dst, void *src, size_t n);

/* ------------------------------ Comum return ------------------------------ */

double		ft_power(double number, int exponent);

/**
 * @brief Convert a string to an integer; The string is composed of optional
 * 			whitespaces, followed by an optional sign, followed by a sequence of
 * 			digits; Only the first sequence of numbers is converted;
 * 
 * @param nptr A pointer to a string to be converted;
 * @return 0 if the string is NULL or if the numbers don't make part of the
 * 			initial sequence; Otherwise, the converted number (int);
 */
int			ft_atoi(char * nptr);

/**
 * @brief Converts a string in octal to an integer; The string is composed of
 * 			optional whitespaces followed by a sequence of octal digits; The
 * 			function only converts the first sequence of octal digits;
 * 
 * @param octal The string to be converted;
 * @return 0 if the string is NULL or if the digits don't make part of the
 * 			initial sequence; Otherwise the converted octal (int);
 */
int			ft_otoi(char * octal);

/**
 * @brief Convert a binary string to an integer; The string is composed of
 * 			optional whitespaces, followed by a sequence of 0s and 1s; Only the
 * 			first sequence of digits is converted;
 * 
 * @param binary A pointer to the string to be converted;
 * @return The converted binary (int); 0 If the string is NULL or if the digits
 *			don't make part of the initial sequence;
 */
int			ft_btoi(char *binary);
int			ft_strcmp(char *s1, char *s2);
int			ft_absolute_number(int number);

/**
 * @brief Convert a hexadecimal string to an integer; The string is composed of
 * 			optional whitespaces, followed by an optional indicator of
 * 			hexadecimal, followed by a sequence of digits or letters from A to
 * 			F;
 * 
 * @param hexadecimal A pointer to the string to be converted;
 * @return 0 if the string is NULL or if the digits and letters don't make part
 * 			of the initial sequence; Otherwise, the converted number (int);
 */
int			ft_htoi(char *hexadecimal);
int			ft_printf(char *string, ...);
int			ft_printf_ln(char *string, ...);
int			ft_memcmp(void *s1, void *s2, size_t n);
int			ft_strncmp(char *s1, char *s2, size_t n);
int			ft_printf_fd(int file_descriptor, char *string, ...);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		ft_putnbr(int n);
void		ft_putchar(char c);
void		ft_putendl(char *s);
void		ft_putstr(char *str);
void		ft_free(void *pointer);
void		ft_bzero(void *s, size_t n);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_free_matrix(void **matrix);
void		ft_putendl_fd(char *s, int fd);
void		ft_swap(void **pointer1, void **pointer2);
void		ft_striteri(char *s, void (*f)(uint32_t, char *));
void		ft_search_replace_chr(char *str, char find, char put);
void		ft_search_replace_str(char *str, char *find, char *put);

#endif
