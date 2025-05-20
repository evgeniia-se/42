#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_lst;
    t_list  *elem;
    void    *content;

    new_lst = 0;
    while (lst)
    {
        content - f(lst->content);
        elem = ft_lstnew(content);
        if (!elem)
        {
            ft_lstclear(&new_lst, del);
            return (0);
        }
        ft_lstadd_back(&new_lst, elem);
        lst = lst->next;
    }
    return (new_lst);
}
