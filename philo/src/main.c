/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:41:05 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/20 16:19:01 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	philo(char **argv)
{
	t_philo	**philo_tab;
	int		ret;

	philo_tab = init_struct_philo(argv);
	if (!philo_tab)
		return (1);
	if (init_mutex(philo_tab, philo_tab[0]->params, philo_tab[0]->nb_philo))
	{
		destroy_philo(philo_tab, ft_atoi(argv[1]));
		return (1);
	}
	if (DB_PARAMS)
		print_params(philo_tab[0]->params);
	if (DB_PHILO)
		print_all_philo(philo_tab, philo_tab[0]->nb_philo);
	ret = threadator(philo_tab, philo_tab[0]->params, philo_tab[0]->nb_philo);
	destroy_philo(philo_tab, ft_atoi(argv[1]));
	return (ret);
}

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);
	if (argv[5] && ft_atoi(argv[5]) == 0)
		return (1);
	if (validator(argv))
		return (1);
	philo(argv);
	return (0);
}
