#include "main.h"

/**
 * print_hex - print hex
 * @ap: argument pointer
 * @params: parameters struct
 * Return: n of bytes
 */

int print_hex(va_list ap, params_t *params)
{
unsigned long l;
char *str;
int c = 0;
if (params->l_modifier)
	l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
	l = (unsigned short int)va_arg(ap, unsigned int);
else
	l = (unsigned int)va_arg(ap, unsigned int);
str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
if (params->hashtag_flag && l)
{
	*--str = 'x';
	*--str = '0';
}
params->unsign = 1;
return (c += print_number(str, params));
}

/**
 * print_HEX - print hex UPPER
 * @ap: argument pointer
 * @params: parameters struct
 * Return: n of bytes
 */

int print_HEX(va_list ap, params_t *params)
{
unsigned long l;
char *str;
int c = 0;
if (params->l_modifier)
	l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
	l = (unsigned short int)va_arg(ap, unsigned int);
else
	l = (unsigned int)va_arg(ap, unsigned int);
str = convert(l, 16, CONVERT_UNSIGNED, params);
if (params->hashtag_flag && l)
{
	*--str = 'X';
	*--str = '0';
}
params->unsign = 1;
return (c += print_number(str, params));
}
/**
 * print_octal - print octal 8
 * @ap: argument pointer
 * @params: parameters struct
 * Return: n of bytes
 */
int print_octal(va_list ap, params_t *params)
{
unsigned long l;
char *str;
int c = 0;
if (params->l_modifier)
	l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
	l = (unsigned short int)va_arg(ap, unsigned int);
else
	l = (unsigned int)va_arg(ap, unsigned int);
str = convert(l, 8, CONVERT_UNSIGNED, params);
if (params->hashtag_flag && l)
{
	*--str = '0';
}
params->unsign = 1;
return (c += print_number(str, params));
}
/**
 * print_binary - print octal 8
 * @ap: argument pointer
 * @params: parameters struct
 * Return: n of bytes
 */
int print_binary(va_list ap, params_t *params)
{
unsigned long l;
char *str;
int c = 0;
if (params->l_modifier)
	l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
	l = (unsigned short int)va_arg(ap, unsigned int);
else
	l = (unsigned int)va_arg(ap, unsigned int);
str = convert(l, 2, CONVERT_UNSIGNED, params);
if (params->hashtag_flag && l)
{
	*--str = '0';
}
params->unsign = 1;
return (c += print_number(str, params));
}
