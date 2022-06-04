#include "ft_printf.h"

int	ft_put_char(char c)
{
	int	res;
	
	res = 0;
	res += write(1, &c, 1);
	return (res);
}

int	ft_put_str(char *str)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		res += write(1, &str[i], 1);
		i++;
	}
	return (res);
}

int	ft_put_number(long double a, int base, char s)
{
	char	*arg;
	int		res;

	res = 0;
	if (s == 'X')
		arg = "0123456789ABCDEF";
	else
		arg = "0123456789abcdef";
	if (a < 0 && (s == 'd' || s == 'i'))
	{
		write(1, "-", 1);
		a *= -1;
		res++;
	}
	if (a >= base)
		res += ft_put_number(a / base, base, s);
	res += write(1, &arg[(unsigned long)a % base], 1);
	return (res);
}

int	ft_kontrolcu(const char *str, va_list args, int i)
{
	int	sayac;

	sayac = 0;
	if (str[i] == '%')
		sayac += ft_put_char('%');
	else if (str[i] == 'c')
		sayac += ft_put_char(va_arg(args, int));
	else if (str[i] == 's')
		sayac += ft_put_str(va_arg(args, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		sayac += ft_put_number(va_arg(args, int), 10, str[i]);
	else if (str[i] == 'u')
		sayac += ft_put_number(va_arg(args, unsigned int), 10, str[i]);
	else if (str[i] == 'X' || str[i] == 'x')
		sayac += ft_put_number(va_arg(args, unsigned int), 16, str[i]);
	else if (str[i] == 'p')
	{
		sayac += ft_put_str("0x");
		sayac += ft_put_number(va_arg(args, unsigned long int), 16, str[i]);
	}
	return (sayac);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		sonvurus;

	i = 0;
	sonvurus = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			sonvurus += ft_kontrolcu(s, args, i);
		}
		else
			sonvurus += ft_put_char(s[i]);
		i++;
	}
	va_end(args);
	return (sonvurus);
}
