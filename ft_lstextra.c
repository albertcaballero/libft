/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:02:26 by alcaball          #+#    #+#             */
/*   Updated: 2023/05/30 13:01:13 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (ft_lstsize(*lst) > 0)
	{
		temp = *lst;
		del((*lst)->content);
		*lst = temp->next;
		free (temp);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlist;
	t_list	*temp;
	void	*content;

	if (!lst)
		return (NULL);
	nlist = NULL;
	temp = NULL;
	ft_lstadd_back(&nlist, temp);
	while (lst)
	{
		content = f(lst->content);
		temp = ft_lstnew(content);
		if (!temp)
		{
			ft_lstclear(&nlist, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&nlist, temp);
		lst = lst->next;
	}
	return (nlist);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free (lst);
}
