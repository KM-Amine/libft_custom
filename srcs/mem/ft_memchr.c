#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char * str;
    unsigned char cst;
    size_t i;

    str = (unsigned char *)s;
    cst = (unsigned char)c;

    if( c > 255 || c < 0)
        return 0;
    if (str ==NULL)
        return 0;
    i =0;
    while(i <n)
    {
        if(str[i]==cst)
            return(void*)&str[i];
        i++;
    }
    return 0;
}