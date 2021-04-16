/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 01:27:21 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 01:32:19 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

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

static	int		create_file(char *name)
{
	int		fd;
	char	*filename;

	filename = ft_strjoin(name, ".bmp");
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	free(filename);
	return (fd);
}

static void		ft_saves(t_config config, t_data mlx, int tag)
{
	char		*name;
	t_bmpheader	header;
	int			fd;
	int			y;

	y = config.R_y;
	name = ft_strjoin("camera_", ft_itoa(tag));
	fd = create_file(name);
	create_header(config, &header);
	init_bmpheader(fd, header);
	while (--y >= 0)
	{
		write(fd, &mlx.addr[y * mlx.line_length], mlx.line_length);
	}
	close(fd);
	free(name);
}

void			ft_save(t_config configs)
{
	int	tag;

	t_imgg	*temp;
	tag = 1;
	temp = configs.img;
	while(temp->next)
	{
		ft_saves(configs,temp->content,tag);
		tag++;
		temp = temp->next;
	}
	ft_saves(configs,temp->content,tag);
}
