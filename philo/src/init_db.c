/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_db.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:28:40 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/02 11:48:15 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	print_params(t_params *params)
{
	printf("\nPRINT PARAMS\n");
	printf("nb_philo et fork : %d\n", params->fork);
	printf("time to die : %d\n", params->time_to_die);
	printf("time to eat : %d\n", params->time_to_eat);
	printf("time to sleep : %d\n", params->time_to_sleep);
	if (params->round)
		printf("nb round  : %d\n", params->round);
	printf("\n");
}

void	print_philo(t_philo *philo)
{
	printf("je suis le philo %d\n", philo->print_id);
	printf("je suis le philo avec l'id %d\n", philo->id);
	printf("Mon adresse est %p\n", philo);
	printf("Ma fork est %p\n", philo->fork);
	printf("Ma next fork est %p\n\n", philo->next_fork);
}

void	print_all_philo(t_philo **philo, int nb_philo)
{
	int	i;

	i = 0;
	printf("\nPRINT PHILO\n");
	if (philo[i]->impair)
		printf("Le nombre de philo est impair\n");
	while (i < nb_philo)
	{
		print_philo(philo[i]);
		i++;
	}
}
