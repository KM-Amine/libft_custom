#include "libft.h"
#include<stdio.h>

#include <string.h>
int main (int argc ,char **argv)
{
    (void)argc;
    (void)argv;
   //printf("%ld",ft_strlen(ft_itoa(ft_atoi(argv[1]))));
   //ft_putnbr_fd(ft_atoi(argv[1]),1);
   //ft_split(argv[1],*argv[2]);
    t_list *lst;
    lst =ft_lstnew("hello");
    ft_lstadd_front(&lst,ft_lstnew("world"));
    ft_lstadd_front(&lst,ft_lstnew("philip"));
    printf("\033[31m%s\n",(char*)ft_lstlast(lst)->content);
} 
