/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:57:55 by moulmado          #+#    #+#             */
/*   Updated: 2022/08/03 15:53:47 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# define WAIT_TIME 100
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <unistd.h>

enum
{
	false,
	true
};

typedef struct s_info
{
	short	philo_nb;
	short	time_2_die;
	short	time_2_eat;
	short	time_2_sleep;
	short	nb_must_eat;
	short	eat_goal;
	short	start_time;
	short	end;
}				t_info;

typedef struct s_fork
{
	short			inuse;
	short			last_user;
	pthread_mutex_t	lock;
}				t_fork;

typedef struct s_philo
{
	pthread_t		philo_thread;
	pthread_t		life_watcher;
	t_info			*p_info;
	short			philo_id;
	short			last_time_2_eat;
	short			times_has_eaten;
	t_fork			*fork;
	pthread_mutex_t	death_check;
	struct s_philo	*next;
}				t_philo;

//tools
int		parse(int ac, char **av);
int		ft_atoi(const char *s);
int		current_time(void);
void	*lyfe_cycle(void *arg);
void	*death_watcher(void	*arg);
void	msg_output(t_philo *philo, char *status);
void	usleep_x(short sleep_time_micro);
void	prepare_2_eat(t_philo *philo);

//args_management
t_philo	*lst_create(int n, t_info *p_info);

#endif