#include "../include/header.h"

static int ft_resizeColor(float a)
{
        if (a >= 1)
        {
                return 255;
        }
        else if (a <= 0)
        {
                return 0;
        }
        else
        {
                return (ceil(255 * a));
        }
}

static void		init_bmpheader(int fd, t_bmpheader header)
{
	write(fd, &header.type, 2);
	write(fd, &header.size, 4);
	write(fd, &header.reserved, 4);
	write(fd, &header.offset, 4);
	write(fd, &header.dib_header_size, 4);
	write(fd, &header.width_px, 4);
	write(fd, &header.height_px, 4);
	write(fd, &header.num_planes, 2);
	write(fd, &header.bpp, 2);
	write(fd, &header.compression, 4);
	write(fd, &header.img_size_bytes, 4);
	write(fd, &header.x_resolution_ppm, 4);
	write(fd, &header.y_resolution_ppm, 4);
	write(fd, &header.num_colors, 4);
	write(fd, &header.important_colors, 4);
}

static void		create_header(t_config config, t_bmpheader *header)
{
	header->type = 0x4D42;
	header->size = ((config.R_x + config.R_y) * 4) + 54;
	header->reserved = 0x0;
	header->offset = 54;
	header->dib_header_size = 40;
	header->width_px = config.R_x;
	header->height_px = config.R_y;
	header->num_planes = 1;
	header->bpp = 32;
	header->compression = 0;
	header->img_size_bytes = ((config.R_x + config.R_y) * 4);
	header->x_resolution_ppm = 2000;
	header->y_resolution_ppm = 2000;
	header->num_colors = 0;
	header->important_colors = 0;
}

static	int create_file(char *name)
{
	int		fd;
	char	*filename;

	filename = ft_strjoin(name, ".bmp");
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	free(filename);
	return (fd);
}

static	char *color_hex(t_color c)
{
	char *resp;
	char *R;
	char *G;
	char *B;
	char *temp;

	R = ft_itoa(ft_resizeColor(c.red));
	G = ft_itoa(ft_resizeColor(c.green));
	B = ft_itoa(ft_resizeColor(c.blue));


	// R = ft_itoa_hex(ft_resizeColor(c.red), HEX_BASE_L);
	// G = ft_itoa_hex(ft_resizeColor(c.green), HEX_BASE_L);
	// B = ft_itoa_hex(ft_resizeColor(c.blue), HEX_BASE_L);

	// if (ft_strlen(R) == 1)
	// {
	// 	temp = ft_strjoin("0",R);
	// 	free(R);
	// 	R = temp;

	// }
	// if (ft_strlen(G) == 1)
	// {
	// 	temp = ft_strjoin("0",G);
	// 	free(G);
	// 	G = temp;

	// }
	// if (ft_strlen(B) == 1)
	// {
	// 	temp = ft_strjoin("0",B);
	// 	free(B);
	// 	B = temp;

	// }

	temp = ft_strjoin(B,G);
	resp = ft_strjoin(temp,R);
	free(R);
	free(G);
	free(B);
	free(temp);
	return(resp);
}

void	ft_save(t_config config, t_canvas canvas, int tag)
{
	char		*name;
	t_bmpheader	header;
	int			fd;
	int			y;
	int 		i;
	char		*line;

	y = config.R_y;
	name = ft_strjoin("camera_", ft_itoa(tag));
    fd = create_file(name);
	create_header(config, &header);
	init_bmpheader(fd, header);
	while (--y >= 0)
	{
		i = 0;
		while (i < config.R_x)
		{
			line = color_hex(canvas.pixel[y][i]);
			write(fd, line, ft_strlen(line));
			i++;
		}
		write(fd, "0", ft_strlen("0"));
	}
	close(fd);
	free(name);
}