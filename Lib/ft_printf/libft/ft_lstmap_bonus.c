/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: NajiKanounji <NajiKanounji@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 02:04:44 by NajiKanounj   #+#    #+#                 */
/*   Updated: 2022/11/07 19:21:41 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_create_new(void *content, void (*del)(void *))
{
	t_list	*new_node;

	new_node = ft_lstnew(content);
	if (!new_node)
	{
		ft_lstclear(&new_node, del);
		del(content);
	}
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*root;
	void	*con;

	if (!lst)
		return (NULL);
	root = ft_create_new(f(lst->content), del);
	while (lst->next)
	{
		lst = lst->next;
		con = f(lst->content);
		new = ft_lstnew(con);
		if (!new)
		{
			ft_lstclear(&root, del);
			del(con);
		}
		ft_lstadd_back(&root, new);
	}
	return (root);
}
