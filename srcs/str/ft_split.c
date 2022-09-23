#include "libft.h"
#include <stdio.h>

static void free_all(char **tab,int len)
{
	int	i;

	i = 0;
	while (i <len)
    {
		free(tab[i]);
        i++;
    }
    free(tab);

}

static int count(char *str, char c)
{
    int i;

    while (*str == c)
        str++;

    i = 0;
    while(ft_strchr(str,c))
    {
        str = ft_strchr(str,c) + 1;
        if (*str == c)
            continue;
        i++;
    }
    if (str[0])
        i++;
    return i;
}
static char **allocate_total(char *str,char c)
{
    int i;
    char **total;
    i =count(str,c);    
    total = calloc(i+1,sizeof(char*));
    if (!total)
        return NULL;
    total[i]=NULL;
    return total;
}
static char **allocate_strings(char *str,char c,char **total)
{
    int j;
    int n;
    int i;
    char *tmp;

    if(total == NULL)
        return NULL;
    i = count(str,c);
    while (*str == c)
        str++;
    j = 0;
    n = 0;
    while(j < i)
    {
        if (n == 1)
            str = ft_strchr(str,c) + 1;
        if (*str == c)
            continue;
        n = 1;
        tmp=ft_strchr(str,c);
        total[j] = ft_substr(str,0,tmp -str);
        if (!total[j])
        {
            free_all(total,j);
            return NULL;
        }
        j++;
    }
    return total;
}
char **ft_split(char const *s, char c)
{ 
	if (!s)
		return (NULL);
    return allocate_strings((char*)s,c,allocate_total((char*)s,c));
    //use ft_strtim
}
