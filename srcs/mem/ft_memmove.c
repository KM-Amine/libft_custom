#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d ;
	unsigned char *s;
	size_t i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;

	if (!d || !s)
		return (dest);

    i = n-1;
    if(dest < src)
    {
        ft_memcpy(dest, src, n);
    }
    else
    {
        while((int)i>=0)
        {
            d[i] = s[i];
            i--;
        }
    }

    return dest;
}