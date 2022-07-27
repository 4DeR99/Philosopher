/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:57:55 by moulmado          #+#    #+#             */
/*   Updated: 2022/07/27 14:06:04 by moulmado         ###   ########.fr       */
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
	pthread_mutex_t	*fork;
	t_info			*p_info;
	struct s_arg	*next;
}				t_arg;

//tools
int	parse(int ac, char **av);
int	ft_atoi(const char *s);
int	current_time(void);

//args_management
t_arg	*lst_create(int n, t_info *p_info);
void	lst_add(t_arg *p_arg, t_arg *_2add);

#endif