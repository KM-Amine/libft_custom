#include "libft.h"

char *ft_strdup(const char *s)
{
	char	*result;
	size_t	len;

	len = ft_strlen((char*)s) + 1;
	result = ft_calloc(len , sizeof(char));
	if (!result)
		return (0);
	ft_strlcpy(result, s, len);
	return (result);
}
