/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:46:27 by moulmado          #+#    #+#             */
/*   Updated: 2022/08/22 11:34:05 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	destruction(t_philo *philo, t_info *inf)
{
	t_philo	*tmp;
	short	limit;

	limit = 0;
	if (philo)
	{
		while (limit < inf->philo_nb && philo)
		{
			tmp = philo;
			philo = philo->next;
			pthread_mutex_destroy(&tmp->fork->lock);
			free(tmp->fork);
			free(tmp);
			limit++;
		}
	}
	if (inf)
	{
		pthread_mutex_destroy(&inf->printing);
		free(inf);
	}
}
