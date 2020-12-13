#include "../include/header.h"

t_color multicolorV(t_color c1, t_color c2)
{
        t_color c;

	c.red = c1.red * c2.red;
	c.green = c1.green * c2.green;
	c.blue = c1.blue * c2.blue;

        return c;
}
