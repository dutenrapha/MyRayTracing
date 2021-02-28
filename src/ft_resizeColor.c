#include "../include/header.h"

int ft_resizeColor(float a)
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