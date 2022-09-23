#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int i;

	i= (int)ft_strlen(s)-1;

	while (i >= 0)
	{
		if(s[i] == c)
			return ((char*)&s[i]);
		i--;
	}
	return(0);
}
