#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    int i;
    
    if(!(char*)s)
        return NULL;
    if( c > 255 || c < 0)
        return 0;
    i =0;
    while(s[i])
    {
        if ( c == s[i])
            return ((char*)&s[i]);
        i++;
    }
    return (0);
}