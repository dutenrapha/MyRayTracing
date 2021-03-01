#include "../include/header.h"

void ft_readfile(t_config *config,char *argv[])
{
    int			fd;
	int			ii;
	int			tag;
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
	tag = 0;
	while ((ii = get_next_line(fd, &line)) > 0)
	{	
		if (line != NULL && *line != '\0')
		{
			ft_conf(&config,line,tag);
			free(line);
		}
		tag++;
	}
	tag++;
	if (line != NULL && *line != '\0')
	{
		ft_conf(&config,line,tag);
		free(line);
	}
}