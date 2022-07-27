/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:34:45 by moulmado          #+#    #+#             */
/*   Updated: 2022/07/27 14:05:36 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_arg	*lst_create(int n, t_info *p_info)
{
	t_arg			*p_arg;
	pthread_mutex_t	*fork;

	
	p_arg = malloc(sizeof(t_arg *));
	pthread_mutex_init(fork, NULL);
	p_arg->fork = fork;
	p_arg->last_time_2_eat = current_time();
	p_arg->philo_id = n;
	p_arg->p_info = p_info;
	p_arg->next = NULL;
	return (p_arg);
}

void	lst_add(t_arg *p_arg, t_arg *_2add)
{
	while(p_arg->next)
		p_arg = p_arg->next;
	p_arg->next = _2add;
}