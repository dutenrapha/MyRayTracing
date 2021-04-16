#include "../include/header.h"

bool ft_readfile(t_config *config,char *argv[])
{
    int			fd;
	int			ii;
	char    	*line;

	config->c_cameras = NULL;
	config->l_lights = NULL;
	config->o_objects = NULL;
	config->c_canvas = NULL;
	config->img = NULL;
	config->img_init = NULL;
	line = NULL;
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		ft_printf("%s\n", ft_error("000"));
        exit(0);
	}
	while ((ii = get_next_line(fd, &line)) > 0)
	{
		if (line != NULL && *line != '\0' && *line != '#')
		{
			if(!is_valid(line))
			{
				return(false);
			}
			ft_conf(&config,line);
			free(line);
		}
	}
	if (line != NULL && *line != '\0')
	{
		if(!is_valid(line))
		{
			return(false);
		}
		ft_conf(&config,line);
		free(line);
	}
	return (true);
}
