/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:28:54 by ylila             #+#    #+#             */
/*   Updated: 2019/04/09 16:35:09 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *curr;

	if (alst && *alst && del)
	{
		curr = *alst;
		while (curr)
		{
			*alst = (*alst)->next;
			ft_lstdelone(&curr, del);
			curr = *alst;
		}
	}
}
