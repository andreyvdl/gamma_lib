/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:00:37 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/26 22:10:10 by adantas-         ###   ########.fr       */
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

/**
 * @brief GNL buffer size, it reads 4096 bytes (4Kb)
 */
# define BUFFER_SIZE 4096
/**
 * @brief Redefinition of NULL, 0x0 is compatible with MacOS and Linux as an
 * universal null pointer
 */
# define NIL 0x0

/**
 * @brief A magic number for the ft_rand function, it's a prime number
 */
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

/**
 * @brief Abstraction of char * type
 */
typedef char*	t_str;

/**
 * @brief Abstraction of char ** type
 */
typedef char**	t_matrix;

/* =============================== Functions =============================== */
/* ------------------------------ Binary tree ------------------------------ */

/**
 * @brief Creates a new node of the binary tree;
 * 
 * @param item A pointer to the content to be put in the node;
 * @return A pointer to the new node;
 */
t_btree		*ft_btree_create_node(void *item);

/**
 * @brief Call a function that apply a fix after going through all left nodes;
 * 
 * @param root A pointer to the root of the tree;
 * @param applyf A pointer to the function that will apply the fix;
**/
void		ft_btree_apply_infix(t_btree *root, void (*applyf)(void *));

/**
 * @brief Call a function to apply a fix before going to the next node;
 * 
 * @param root A pointer to the root of the tree;
 * @param applyf A pointer to the function that will apply the fix;
**/
void		ft_btree_apply_prefix(t_btree *root, void (*applyf)(void *));

/**
 * @brief Call a function to apply a fix after going through all nodes;
 * 
 * @param root A pointer to the root of the tree;
 * @param applyf A pointer to the function to apply the fix;
**/
void		ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *));

/**
 * @brief Insert a node in the binary tree; The low values goes to the left and
 * 			the high or equal values goes to the right; If the root is NULL, the
 * 			function will create a new node and set it as the root;
 * 
 * @param root The root of the binary tree;
 * @param item Will be the content of the new node;
 * @param cmpf Function that compares the content of the nodes (void *, void *);
 */
void		ft_btree_insert_data(t_btree **root, void *item, \
								int (*cmpf)(void *, void *));

/**
 * @brief Search an item in the binary tree based on the data reference with the
 * 			function cmpf;
 * 
 * @param root A pointer to the root of the binary tree;
 * @param data_ref A pointer to the data reference;
 * @param cmpf A pointer to the function that will compare the data reference;
 * @returns NULL if the data reference can't be found or a pointer to the item
 * 			found (void *);
 */
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

/**
 * @brief Checks for an alphanumeric character;
 * 
 * @param c The character to be checked;
 * @return If the character is alphanumeric, returns true; otherwise, false;
 */
bool		ft_isalnum(int c);

/**
 * @brief Checks for an alphabetic character;
 * 
 * @param c The character to be checked;
 * @return true if the character is an alphabetic character; otherwise, false;
 */
bool		ft_isalpha(int c);

/**
 * @brief Checks for an ASCII character;
 * 
 * @param c the character to be checked;
 * @return true if the character is an ASCII character; otherwise, false;
 */
bool		ft_isascii(int c);

/**
 * @brief Checks for space or tab;
 * 
 * @param c The character to be checked;
 * @return true if the character is space or tab; otherwise, false;
 */
bool		ft_isblank(int c);

/**
 * @brief Checks for a digit;
 * 
 * @param c The character to be checked;
 * @return true if the character is a digit from 0 to 9; otherwise, false;
 */
bool		ft_isdigit(int c);

/**
 * @brief Checks for a lowercase character;
 * 
 * @param c The character to be checked;
 * @return true if the character is lowercase; otherwise, false;
 */
bool		ft_islower(int c);

/**
 * @brief Checks for any printable character including space;
 * 
 * @param c The character to be checked;
 * @return true if the character is printable; otherwise, false;
 */
bool		ft_isprint(int c);

/**
 * @brief Checks for any whitespace character;
 * 
 * @param c The character to be checked;
 * @return true if the character is a whitespace; otherwise, false;
 */
bool		ft_isspace(int c);

/**
 * @brief Checks for an uppercase letter;
 * 
 * @param c The character to be checked;
 * @return true if the character is uppercase; otherwise, false;
 */
bool		ft_isupper(int c);

/**
 * @brief Checks for hexadecimal digits;
 * 
 * @param c The character to be checked;
 * @return true if the character is hexadecimal; otherwise, false;
 */
bool		ft_isxdigit(int c);

/**
 * @brief Checks if the number is prime;
 * 
 * @param nb the number to be checked;
 * @return true if the number is prime; otherwise, false;
 */
bool		ft_isprime(int nb);
size_t		ft_strlen(const t_str s);
size_t		ft_rand(size_t seed, size_t min, size_t max);
size_t		ft_strspn(const t_str s, const t_str accept);
size_t		ft_strcspn(const t_str s, const t_str reject);
size_t		ft_strlcat(t_str dst, const t_str src, size_t size);
size_t		ft_strlcpy(t_str dst, const t_str src, size_t size);

/* -------------------------- Comum pointer return -------------------------- */

/**
 * @brief Converts an integer to a string;
 * 
 * @param n The integer to be converted;
 * @return NULL if the allocation fails, otherwise the string (char *);
 */
t_str		ft_itoa(int n);

/**
 * @brief Converts an integer to a hexadecimal string;
 * 
 * @param n The integer to be converted;
 * @return NULL if allocation fails or if n is negative, otherwise the string
 * 			(char *);
 */
t_str		ft_itoh(int n);

/**
 * @brief Converts an integer to octal
 * 
 * @param n The integer to be converted
 * @return NULL if the integer is negative; Otherwise, the converted number
 * 			in octal (char *);
 */
t_str		ft_itoo(int n);

/**
 * @brief Converts an integer to a binary string;
 * 
 * @attention The size of the string is based from the MSB of the integer;
 *
 * @param nbr the integer to be converted;
 * @return NULL if the allocation fails or if nbr is negative, otherwise the
 * 			string (char *);
 */
t_str		ft_itob(int nbr);
t_str		ft_strrev(t_str str);
t_str		get_next_line(int fd);
t_str		ft_strupcase(t_str str);
t_str		ft_strdup(const t_str s);
t_str		ft_strlowcase(t_str str);
t_str		ft_strcapitalize(t_str str);
t_matrix	ft_matrixdup(t_matrix matrix);
t_str		ft_strchr(const t_str s, int c);
t_str		ft_strcpy(t_str dst, t_str src);
t_matrix	ft_split(t_str const s, char c);
t_str		ft_strcat(t_str dest, t_str src);
t_str		ft_strrchr(const t_str s, int c);
t_str		ft_strjoin(t_str const s1, t_str const s2);
t_str		ft_strtrim(t_str const s1, t_str const set);
t_str		ft_strpbrk(const t_str s, const t_str accept);
t_str		ft_strstr(const t_str str, const t_str to_find);
t_str		ft_substr(t_str const s, uint32_t start, size_t len);
t_str		ft_strmapi(t_str const s, char (*f)(uint32_t, char));
t_str		ft_strnstr(const t_str big, const t_str little, size_t len);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);

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
int			ft_atoi(t_str nptr);

/**
 * @brief Converts a string in octal to an integer; The string is composed of
 * 			optional whitespaces followed by a sequence of octal digits; The
 * 			function only converts the first sequence of octal digits;
 * 
 * @param octal The string to be converted;
 * @return 0 if the string is NULL or if the digits don't make part of the
 * 			initial sequence; Otherwise the converted octal (int);
 */
int			ft_otoi(t_str octal);

/**
 * @brief Convert a binary string to an integer; The string is composed of
 * 			optional whitespaces, followed by a sequence of 0s and 1s; Only the
 * 			first sequence of digits is converted;
 * 
 * @param binary A pointer to the string to be converted;
 * @return The converted binary (int); 0 If the string is NULL or if the digits
 *			don't make part of the initial sequence;
 */
int			ft_btoi(t_str binary);
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
int			ft_htoi(t_str hexadecimal);
int			ft_printf(const char *string, ...);
int			ft_printf_ln(const char *string, ...);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_printf_fd(int file_descriptor, const char *string, ...);
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
