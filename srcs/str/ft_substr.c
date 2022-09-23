#include "libft.h"

char *ft_substr(char const *s, unsigned int start,size_t len)
{
    char *str;

    if (start >= ft_strlen(s))
        return ((char *)ft_calloc(1,sizeof(char)));// or return NULL ????
    if (ft_strlen(s) <= start + len)
        str = ft_calloc(ft_strlen(s) - start +1 ,sizeof(char));
    else
        str = ft_calloc(len + 1,sizeof(char));    
    if (s == NULL || str == NULL)
        return NULL;
    ft_strlcpy(str,&s[start],len+1);
    return str;
}