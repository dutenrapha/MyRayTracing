/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:49:24 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 20:00:09 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static	void	ft_int(t_config *config)
{
	config->c_cameras = NULL;
	config->l_lights = NULL;
	config->o_objects = NULL;
	config->c_canvas = NULL;
	config->img = NULL;
	config->img_init = NULL;
}

static	bool	ft_aux(char *line, t_config *config)
{
	if (line != NULL && *line != '\0')
	{
		if (!is_valid(line))
			return (false);
		ft_conf(&config, line);
		free(line);
	}
	return (true);
}

bool			ft_readfile(t_config *config, char *argv[])
{
	int		fd;
	int		ii;
	char	*line;

	line = NULL;
	ft_int(config);
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		ft_printf("%s\n", ft_error("000"));
		exit(0);
	}
	while ((ii = get_next_line(fd, &line)) > 0)
	{
		if (line != NULL && *line != '\0' && *line != '#')
		{
			if (!is_valid(line))
				return (false);
			ft_conf(&config, line);
			free(line);
		}
	}
	if (!ft_aux(line, config))
		return (false);
	return (true);
}
