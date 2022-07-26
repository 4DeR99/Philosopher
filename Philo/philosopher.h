/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:57:55 by moulmado          #+#    #+#             */
/*   Updated: 2022/07/26 18:45:11 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# define YES 1
# define NO 0
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <unistd.h>

typedef struct s_info
{
	int	philo_nb;
	int	time_2_die;
	int	time_2_eat;
	int	time_2_sleep;
	int	nb_must_eat;
	int	start_time;
}				t_info;

typedef struct s_arg
{
	int				philo_id;
	int				last_time_2_eat;
	pthread_mutex_t	fork;
	t_info			*p_info;
}				t_arg;

int	parse(int ac, char **av);
int	ft_atoi(const char *s);
int	current_time(void);

#endif