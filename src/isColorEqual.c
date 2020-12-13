#include "../include/header.h"

bool isColorEqual(t_color c1, t_color c2)
{
	if (fabs(c1.red - c2.red) > EPSILON)
        {
                return false;
        }
        else if (fabs(c1.green - c2.green) > EPSILON)
        {
                return false;
        }
        else if (fabs(c1.blue - c2.blue) > EPSILON)
        {
                return false;
        }
        else
        {
                return true;
        }
}
