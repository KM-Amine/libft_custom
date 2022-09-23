#include "libft.h"
#include <stdio.h>

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

static char *allocate(int n)
{
    char *result;
    int len;

    len = lenth(n);    
    result = calloc(len+1,sizeof(char));
    if (!result)
        return NULL;
    return result;
}
char *ft_itoa(int n)
{
    char *result;
    if (n == 0)
    {
        result =calloc(2,sizeof(char));
        if(!result)
            return NULL;
        ft_strlcpy(result,"0",2);
        return result;
    }
    return fill(n,allocate(n),lenth(n));
}