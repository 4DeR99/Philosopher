/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_b.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:46:21 by moulmado          #+#    #+#             */
/*   Updated: 2022/08/16 14:23:51 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_B_H
# define PHILOSOPHER_B_H

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

//tools
int				ft_atoi(const char *s);
int				parse(int ac, char **av);
unsigned int	current_time(void);

#endif