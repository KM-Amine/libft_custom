#include "libft.h"
/*
void ft_putnbr_fd(int n, int fd)
{
    long nbr ;
    
    nbr =n;
    if(n < 0)
    {
        ft_putchar_fd('-',fd);
        nbr = -nbr;
    }
    if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
    ft_putchar_fd(nbr % 10 +'0',fd);
    
}
*/

static char *fill(long n, char *result,int len)
{
    int i;

    if(result == NULL)
        return NULL;
    result[len] = '\0';
    if (n<0)
    {
        result[0]='-';
        n=-n;
    }
    i = len -1;
    while(n != 0)
    {
        result[i]=n % 10 +48;
        n = n/10;
        i--;
    }
    return result;
}
static int lenth(int n)
{
    int i;

    i = 0;
    if (n<0)
        i++;
    while(n != 0)
    {
        n = n / 10;
        i++;
    }
    return i;
}
void ft_putnbr_fd(int n, int fd)
{
    char result[12];
    
    if (n == 0)
    {
        ft_putstr_fd("0",fd);
    }
    else 
        ft_putstr_fd(fill(n,result,lenth(n)),fd);
}