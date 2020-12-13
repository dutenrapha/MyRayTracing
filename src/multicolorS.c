#include "../include/header.h"

t_color multicolorS(t_color c1, float a)
{
        t_color c;

        c.red = c1.red * a;
        c.green = c1.green * a;
        c.blue = c1.blue * a;
        return c;
}
