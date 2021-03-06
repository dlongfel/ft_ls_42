/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:11:09 by hluthor           #+#    #+#             */
/*   Updated: 2020/10/12 18:11:13 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			tab_sort(char **tab, int size,
					int (*function)(const char*, const char*))
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	while (j < size)
	{
		i = j - 1;
		tmp = tab[j];
		while (i >= 0 && function(tab[i], tmp) > 0)
		{
			tab[i + 1] = tab[i];
			i--;
		}
		tab[i + 1] = tmp;
		j++;
	}
	return (1);
}

t_file		*initialization_file_list(char **names_list, int argc, int first)
{
	int		i;
	t_file	*start;

	start = NULL;
	(!argc) ? add_file("", ".", &start)
				: tab_sort(names_list, argc, &ft_strcmp);
	i = -1;
	while (++i < argc)
		if (add_file("", names_list[i], &start) == -1 && first)
			ls_error(names_list[i], ERRNO);
	return (start);
}
