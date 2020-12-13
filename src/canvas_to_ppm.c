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

static char *header_canvas_to_ppm(t_canvas *cv, char *init, char *final)
{
	char *str;
	char *temp;
	
	str = ft_strjoin(init, ft_itoa(cv->width));	
	temp = ft_strdup(str);
	free(str);
	str = ft_strjoin(temp," ");
        free(temp);
	temp = ft_strdup(str);
        free(str);
        str = ft_strjoin(temp, ft_itoa(cv->height));
        free(temp);
	temp = ft_strdup(str);
        free(str);	
	str = ft_strjoin(temp, final);
	free(temp);
	return (str);
}

char *canvas_to_ppm(t_canvas *cv)
{
	char *header;
	char *body;
	char *temp;
	int i;
	int j;
	
	header = header_canvas_to_ppm(cv, "P3\n", "\n255");
	i = 0;
	body = ft_strjoin(header, "\n");
	temp = ft_strdup(body);
	free(body);
	free(header);
	while (i < cv->height)
	{
		j = 0;
		while(j < cv->width)
		{
			body = ft_strjoin(temp, ft_itoa(ft_resizeColor(cv->pixel[i][j].red)));	
			free(temp);
			temp = ft_strdup(body);
			free(body);
			body = ft_strjoin(temp, " ");
			temp = ft_strdup(body);
			body = ft_strjoin(temp, ft_itoa(ft_resizeColor(cv->pixel[i][j].green)));
			free(temp);
                        temp = ft_strdup(body);
                        free(body);
                        body = ft_strjoin(temp, " ");
                        temp = ft_strdup(body);
			body = ft_strjoin(temp, ft_itoa(ft_resizeColor(cv->pixel[i][j].blue)));
			free(temp);
                        temp = ft_strdup(body);
                        free(body);
                        if (((j  == cv->width - 1) || i  == cv->height - 1) && (j  == cv->width - 1))	
				body = ft_strjoin(temp, "\n");
                        else
				body = ft_strjoin(temp, " ");
			temp = ft_strdup(body);
			j++;
		}
		i++;
	}	
			
	return (temp);
}










	



