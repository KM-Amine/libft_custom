#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t i;
    size_t dest_len;
    size_t src_len;

    dest_len = ft_strlen(dst);
    src_len = ft_strlen(src);

    if (dstsize <= dest_len)
        return src_len + dstsize;
    
    i = 0;
    while (src[i] && dest_len + i < dstsize -1)
    {
        dst[i+dest_len] = src[i];
        i++;
    }
    dst[i + dest_len] = '\0';
    return src_len + dest_len;  
}