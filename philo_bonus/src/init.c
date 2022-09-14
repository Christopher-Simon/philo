/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christopher <christopher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:42:22 by christopher       #+#    #+#             */
/*   Updated: 2022/09/13 21:16:04 by christopher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

t_params	*get_params(char **argv)
{
	t_params	*params;

	params = ft_calloc(sizeof(t_params), 1);
	if (!params)
		return (NULL);
	params->fork = ft_atoi(argv[1]);
	params->nb_philo = params->fork;
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		params->round = ft_atoi(argv[5]);
	else
		params->round = -1;
	return (params);
}

t_philo	*set_philo(char **argv, t_params *params)
{
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo), 1);
	if (!philo)
		return (NULL);
	philo->params = params;
	philo->nb_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->round = ft_atoi(argv[5]);
	else
		philo->round = -1;
	return (philo);
}

int	add_cycle(t_philo **philo_tab, int nb_philo)
{
	int		i;
	char	*sem_nb;

	i = 0;
	while (i < nb_philo) 
	{
		sem_nb = ft_itoa(philo_tab[i]->id);
		if (!sem_nb)
		{
			while (--i >= 0)
				free(philo_tab[i]->cycle);
			return (1);
		}
		philo_tab[i]->cycle = ft_strjoin(CYCLE, sem_nb);
		free(sem_nb);
		if (!philo_tab[i]->cycle)
		{
			while (--i >= 0)
				free(philo_tab[i]->cycle);
			return (1);
		}
		i++;
	}
	return (0);
}

t_philo	**get_philo(t_philo **philo_tab, char **argv, t_params *params)
{
	int		nb_philo;
	int		i;

	i = 0;
	nb_philo = ft_atoi(argv[1]);
	while (i < nb_philo)
	{
		philo_tab[i] = set_philo(argv, params);
		if (!philo_tab[i])
		{
			while (--i >= 0)
				free(philo_tab[i]);
			return (free(philo_tab), NULL);
		}
		philo_tab[i]->id = i;
		philo_tab[i]->print_id = i + 1;
		if (nb_philo % 2 == 1)
			philo_tab[i]->impair = 1;
		i++;
	}
	if (add_cycle(philo_tab, nb_philo))
	{
		while (--i >= 0)
				free(philo_tab[i]);
			return (free(philo_tab), NULL);
	}
	return (philo_tab);
}

t_philo	**get_data(t_philo **philo_tab, char **argv)
{
	t_params	*params;

	params = get_params(argv);
	if (!params)
		return (NULL);
	philo_tab = get_philo(philo_tab, argv, params);
	if (!philo_tab)
		return (free(params), NULL);
	return (philo_tab);
}

t_philo	**init_struct_philo(char **argv)
{
	t_philo	**philo_tab;
	int		nb_philo;

	nb_philo = ft_atoi(argv[1]);
	philo_tab = ft_calloc(nb_philo, sizeof(t_philo *));
	if (!philo_tab)
		return (NULL);
	philo_tab = get_data(philo_tab, argv);
	if (!philo_tab)
		return (free(philo_tab), NULL);
	return (philo_tab);
}
