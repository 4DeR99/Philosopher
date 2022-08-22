/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:57:55 by moulmado          #+#    #+#             */
/*   Updated: 2022/08/22 11:36:03 by moulmado         ###   ########.fr       */
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
	pthread_mutex_t	printing;
	short			philo_nb;
	unsigned int	time_2_die;
	unsigned int	time_2_eat;
	unsigned int	time_2_sleep;
	short			nb_must_eat;
	short			eat_goal;
	unsigned int	start_time;
	short			end;
	short			stop_philo;
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
	unsigned int	last_time_2_eat;
	short			times_has_eaten;
	t_fork			*fork;
	struct s_philo	*next;
}				t_philo;

//time
unsigned int	current_time(void);
void			usleep_x(unsigned int sleep_time);

//tools
void			*lyfe_cycle(void *arg);
void			*death_watcher(void	*arg);
void			msg_output(t_philo *philo, char *status, short ded);
void			prepare_2_eat(t_philo *philo);
void			putstr_fd_x(char *s, int fd);
void			putchar_fd_x(int c, int fd);

//args_management
int				ft_atoi(const char *s);
int				parse(int ac, char **av);
t_philo			*lst_create(int n, t_info *p_info);
void			destruction(t_philo *philo, t_info *inf);
t_philo			*ascending_philos(t_info *p_info);

#endif