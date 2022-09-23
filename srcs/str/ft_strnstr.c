#include "libft.h"
char *ft_strnstr(const char	*big, const char *little, size_t len)
{
   size_t i;
   int cmp;
   
   if (ft_strlen(little) == 0)
    return (char*)big;

   i = 0;    
   while(big[i] && i + ft_strlen(little)<=len )
   {
        if (big[i] == little[0])
        {
            cmp = ft_strncmp(&big[i],little,ft_strlen(little));
            if(cmp == 0)
                return((char*)&big[i]);
        }
        i++;
   }
   return (NULL);
}
/*char *ft_strnstr(const char	*big, const char *little, size_t len)
{
    int i;
    int j;
    char *temp;
    int found;
    
    if (ft_strlen(little) == 0)
        return (char*)big;

    i = 0;
    found = 0;
    while(big[i])
    {
        j = 0;
        temp = (char*)&big[i];

        if(big[i] == little[j])
        {
            while(big[i])
            {
                if(little[j] == big[i])
                {
                    j++;
                    i++;
                    if(little[j] == '\0' || j == (int)len)
                    {
                        found = 1;
                        break;
                    }
                }
                else
                {
                    if (big[i] == big[i-1])
                        i--;
                    break;
                }
            }
        }
        if (found == 1)
            return temp;
        if (big[i] == '\0')
            break;
        
        i++;
    }
    return NULL;
}*/