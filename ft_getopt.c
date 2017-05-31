/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:49:34 by adaly             #+#    #+#             */
/*   Updated: 2017/05/31 14:53:32 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//static int	ft_getopt_internal(int argc, 

int		ft_getopt(int argc, char const **argv, char const *options, char **optarg)
{
	static int	which_arg;
	int			which_str;
	int			which_char;
	int			counter;
	char		*loc;

	loc = NULL;
	*optarg = NULL;
	if (!which_arg)
		which_arg = 0;
	which_char = 0;
	which_str = 0;
	counter = 0;
	if (argv)
	{
		while (counter <= which_arg && which_str < argc)
		{
			if (argv[which_str][0] == '-')
			{
				while (argv[which_str][which_char])
				{
					if (((loc = ft_strchr(options, argv[which_str][which_char])) && \
					argv[which_str][which_char] != ':'))
					{
						++counter;
						if (counter > which_arg)
						{
							if (loc[1] == ':' && (which_str + 1 < argc))
								*optarg = ft_strdup(argv[which_str + 1]);
							if ((loc[1] == ':' && loc[2] == ':') || loc[1] != ':' || *optarg)
							{
								which_arg = counter;
								return (argv[which_str][which_char]);
							}
						}
					}
					++which_char;
				}
				which_char = 0;
			}
			++which_str;
		}
	}
	return (0);
}
