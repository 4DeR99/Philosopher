/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:34:45 by moulmado          #+#    #+#             */
/*   Updated: 2022/07/26 18:45:28 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_arg	*lst_create(int n, pthread_mutex_t fork, t_info *p_info)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg *));
	arg->fork = fork;
	arg->last_time_2_eat = current_time();
	arg->philo_id = n;
	arg->p_info = p_info;
}