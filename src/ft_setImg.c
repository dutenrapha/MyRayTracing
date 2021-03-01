#include "../include/header.h"

static void ft_set(int YY, int XX, t_canvas c, t_imgg **img,t_config *config)
{
    int     x;
	int     y;
	int R;
	int G;
	int B;
    t_color cor;
    t_data im;
    
    im.img = mlx_new_image(config->mlx, XX, YY);
    im.addr = mlx_get_data_addr(im.img, &im.bits_per_pixel, &im.line_length,
                                 &im.endian);


    y = 0;
    while (y < YY - 1)
    {
        x = 0;
        while (x < XX - 1)
        {
            cor = c.pixel[y][x];
            R = ft_resizeColor(cor.red);
            G = ft_resizeColor(cor.green);
            B = ft_resizeColor(cor.blue);
            my_mlx_pixel_put(&im, x, y, createRGB(R,G,B));
            x++;
        }
        y++;
    }
    n_img(img,im);
}


void 	ft_setImg(t_config *config)
{

    t_cv    *temp;

    temp = config->c_canvas;
    while (temp->next)
    {
        ft_set(config->R_y,config->R_x,temp->content,&config->img, config);
        temp = temp->next;
    }
    ft_set(config->R_y,config->R_x,temp->content, &config->img, config);
    config->img_init = config->img;
}

