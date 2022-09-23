#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    int i;
    int j;
    if (!s1 || !set)
        return NULL;
    i = 0;
    while(s1[i] && ft_strchr(set,s1[i]))
        i++;
    if(s1[i] == '\0')
        return calloc(1,sizeof(char));
    j = ft_strlen(s1) - 1;
    while(ft_strchr(set,s1[j]))
        j--;
    
    return ft_substr(s1,i,j-i+1);
}