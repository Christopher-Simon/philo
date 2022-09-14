/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christopher <christopher@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:41:05 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/14 17:54:28 by christopher      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	philo(char **argv)
{
	t_philo	**philo_tab;
	int		ret;

	philo_tab = init_struct_philo(argv);
	if (!philo_tab)
		return(1);
	if (init_semaphore(philo_tab, philo_tab[0]->params, ft_atoi(argv[1])))
		return(destroy_philo(philo_tab, philo_tab[0]->params, ft_atoi(argv[1])));
	// if (DB_PARAMS)
	// 	print_params(philo_tab[0]->params);
	// if (DB_PHILO)
	// 	print_all_philo(philo_tab, philo_tab[0]->nb_philo);
	ret = forkator(philo_tab, philo_tab[0]->params, philo_tab[0]->nb_philo);
	// ret = 0;
	destroy_philo(philo_tab, philo_tab[0]->params, ft_atoi(argv[1]));
	return (ret);
}

int	main(int argc, char **argv)
{
	//CHECK LE RELINK DU MAKEFILE
	if (argc < 5 || argc > 6)
		return (1);
	if (argv[5] && ft_atoi(argv[5]) == 0)
		return (1);
	if (validator(argv))
		return (1);
	philo(argv);
	return (0);
}
