/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:46:59 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/31 13:33:44 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	(void)argv;
	if (argc != 2)
		return (printf("problem nbr arg\n"), free(data), 1);
	if (init_data(data))
		return (FAILED);
	if (check_arg(argv[1], data))
		return (FAILED);
	if (start_mlx(data))
		return (FAILED);
	printf("fin du programme tout est nickel\n");
	return (SUCCESS);
}
