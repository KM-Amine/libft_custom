#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *ls;

    ls = ft_calloc(1,sizeof(t_list));
    if (!ls)
        return NULL;
    
    ls -> next = NULL;
    ls -> content = content;
    return ls;
}
