#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *result;
    int i;

    if (!s || !f)
		return (NULL);
    result = ft_strdup(s);
    if (!result)
        return NULL;
    i =0;
    while(s[i])
    {
        result[i] = f(i,s[i]);
        i++;
    }
    return result;
}