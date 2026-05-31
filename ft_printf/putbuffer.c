#include "ft_printf.h"

void buffer_putstr(char *s, t_pf_buf* buf)
{
    int i;

    i = 0;
	if (s == NULL)
	    s = "(null)";
	while (s[i]){
        buf_add_char(s[i], buf);
        ++i;
	}
}

void	buffer_putnbr(int n, t_pf_buf* buf)
{
	long	nb;

	nb = (long) n;
	if (nb < 0)
	{
		nb *= -1;
		buf_add_char('-', buf);
	}
	if (nb > 9)
	{
		buffer_putnbr (nb / 10, buf);
		nb = nb % 10;
	}
	if (nb <= 9)
		buf_add_char(nb + '0', buf);
}


void	buffer_putuint(unsigned int n, t_pf_buf* buf)
{
    long	nb;

	nb = (unsigned long) n;
	if (nb > 9)
	{
		buffer_putnbr (nb / 10, buf);
		nb = nb % 10;
	}
	if (nb <= 9)
		buf_add_char(nb + '0', buf);
}
