/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:48:34 by ylila             #+#    #+#             */
/*   Updated: 2019/04/20 14:49:41 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list *curr;

	if (!*alst && new)
		*alst = new;
	else if (alst && *alst && new)
	{
		curr = *alst;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}
