#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str;

    if(s1 == NULL && s2 == NULL)
        return NULL;// or a char with backslash 0
    if(s1 == NULL)
        return ft_strdup(s2);
    if(s2 == NULL)
        return ft_strdup(s1);

    str = ft_calloc(ft_strlen(s1)+ft_strlen(s2)+1,sizeof(char));
    if(str == NULL )
        return NULL;
    ft_strlcpy(str,s1,ft_strlen(s1)+1);
    ft_strlcat(str,s2,ft_strlen(s1)+ft_strlen(s2)+1);
    return str;
}