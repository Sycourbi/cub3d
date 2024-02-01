/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:46:02 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/31 14:02:47 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_color_definition(char *color_def)
{
	int	count_comas;
	int	count_numbers;

	count_comas = 0;
	count_numbers = 0;
	while (*color_def != '\n')
	{
		while (*color_def == ' ' || *color_def == '\t')
			color_def++;
		if ((*color_def >= 48 && *color_def <= 57) || *color_def == ',')
		{
			if (*color_def == ',')
				count_comas++;
			else if ((*color_def >= 48 && *color_def <= 57))
				count_numbers++;
		}
		else
			return (FAILED);
		color_def++;
	}
	if (count_comas != 2 || count_numbers > 9)
		return (FAILED);
	return (SUCCESS);
}

char	*less_space(char *str)
{
	char	*res;
	int		count_num;
	int		i;

	i = 0;
	count_num = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			count_num++;
		i++;
	}
	res = malloc(sizeof(char) * (count_num + 1));
	if (!res)
		return (free(str), NULL);
	i = 0;
	count_num = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res[count_num++] = str[i];
		i++;
	}
	res[count_num] = '\0';
	return (free(str), res);
}

int	*ajout_new_color(char *map)
{
	char	**split;
	int		*res;
	int		size;

	size = 0;
	split = ft_split(map, ',');
	if (!split)
		return (NULL);
	while (split[size])
		size++;
	if (size != 3)
		return (free_tab((void **)split), NULL);
	split[0] = less_space(split[0]);
	split[1] = less_space(split[1]);
	split[2] = less_space(split[2]);
	res = malloc(sizeof(int) * 3);
	if (!res)
		return (free_tab((void **)split), NULL);
	res[0] = ft_atoi(split[0]);
	res[1] = ft_atoi(split[1]);
	res[2] = ft_atoi(split[2]);
	free_tab((void **)split);
	return (res);
}

int	ajout_color(char *map, int j, t_text *texture)
{
	if (map[j] == 'F' && !texture->color_f)
	{
		j++;
		while (map[j] == ' ' || map[j] == '\t')
			j++;
		if (check_color_definition(map + j) == FAILED)
			return (-1);
		texture->color_f = ajout_new_color(map + j);
	}
	else if (map[j] == 'C' && !texture->color_c)
	{
		j++;
		while (map[j] == ' ' || map[j] == '\t')
			j++;
		if (check_color_definition(map + j) == FAILED)
			return (-1);
		texture->color_c = ajout_new_color(map + j);
	}
	else
		return (-1);
	return (0);
}
