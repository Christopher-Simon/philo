/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:42:22 by christopher       #+#    #+#             */
/*   Updated: 2022/09/20 16:21:38 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

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
			return (free(sem_nb), 1);
		philo_tab[i]->cycle = ft_strjoin(CYCLE, sem_nb);
		if (!philo_tab[i]->cycle)
			return (free(sem_nb), 1);
		philo_tab[i]->name_death = ft_strjoin(DEATH, sem_nb);
		if (!philo_tab[i]->name_death)
			return (free(sem_nb), 1);
		free(sem_nb);
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
			return (destroy_philo(philo_tab, params, nb_philo), NULL);
		philo_tab[i]->id = i;
		philo_tab[i]->print_id = i + 1;
		if (nb_philo % 2 == 1)
			philo_tab[i]->impair = 1;
		i++;
	}
	if (add_cycle(philo_tab, nb_philo))
		return (destroy_philo(philo_tab, params, nb_philo), NULL);
	return (philo_tab);
}

t_philo	**get_data(t_philo **philo_tab, char **argv)
{
	t_params	*params;

	params = get_params(argv);
	if (!params)
		return (destroy_philo(philo_tab, NULL, ft_atoi(argv[1])), NULL);
	philo_tab = get_philo(philo_tab, argv, params);
	if (!philo_tab)
		return (NULL);
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
