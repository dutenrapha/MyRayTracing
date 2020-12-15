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

char *canvas_to_ppm(t_canvas *cv)
{
	FILE *fp;
	char *string;
	long fsize;
	int i;
	int j;
	
	fp = fopen("image.ppm", "w+");

	fprintf(fp, "P3\n%d %d\n255\n",cv->width, cv->height);
	i = 0;
	while (i < cv->height)
	{
		j = 0;
		while(j < cv->width)
		{
			if (((j  == cv->width - 1) || i  == cv->height - 1) && (j  == cv->width - 1))
			{
				fprintf(fp, "%d %d %d\n", ft_resizeColor(cv->pixel[i][j].red), ft_resizeColor(cv->pixel[i][j].green), ft_resizeColor(cv->pixel[i][j].blue));
			}
			else
			{
				fprintf(fp, "%d %d %d ", ft_resizeColor(cv->pixel[i][j].red), ft_resizeColor(cv->pixel[i][j].green), ft_resizeColor(cv->pixel[i][j].blue));	
			}
			j++;
		}
		i++;
	}	
 	fclose(fp);
	
	fp = fopen("image.ppm", "rb");
	fseek(fp, 0, SEEK_END);
	fsize = ftell(fp);
	fseek(fp, 0, SEEK_SET); 
	string = malloc(fsize + 1);
	fread(string, 1, fsize, fp);
	fclose(fp);
	string[fsize] = 0;
			
	return (string);
}










	



