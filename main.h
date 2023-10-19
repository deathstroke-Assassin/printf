#ifndef PRINT_F
#define PRINT_F

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - struct params
 * @unsign: flag for unsigned
 * @space_flag:  flag
 * @hashtag_flag: #flag
 * @zero_flag: 0_flag
 * @minus_flag: -_flag
 * @width: printed width flag
 * @plus_flag: +_flag
 * @precision: printed value precision flag
 * @h_modifier: short mod
 * @l_modifier: long mod
 *
 */
typedef struct parameters
{
	unsigned int unsign            : 1;
	unsigned int space_flag        : 1;
	unsigned int hashtag_flag      : 1;
	unsigned int zero_flag         : 1;
	unsigned int minus_flag        : 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier        : 1;
	unsigned int l_modifier        : 1;
	unsigned int plus_flag         : 1;
} params_t;

/**
 * struct specifier - struct token
 * @specifier: format token
 * @f: funcion pointer
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

int _puts(char *str);

/**
 * _putchar - putchar a
 *
 * @c: a char
 * Return: always 0
*/

int _putchar(int c);

/* print_functions */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/* number.c */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* specifier.c */
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/* convert_number.c */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);

/* simple_printers.c */
int print_from_to(char *start, char *stop, char *except);
int print_rot13(va_list ap, params_t *params);
int print_rev(va_list ap, params_t *params);

/* print_number.c */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* params.c */
void init_params(params_t *params, va_list);
/* string_fields.c */
char *get_precision(char *p, params_t *params, va_list);

/* printf.c*/
int _printf(const char *format, ...);

#endif
