#include "../include/header.h"

void	check_axis(float origin, float direction, float *tmin,float *tmax)
{
    float   tmin_numerator;
    float   tmax_numerator;
    float   temp;

    tmin_numerator = (-1 - origin);
    tmax_numerator = (1 - origin);
    
    if (fabs(direction) >= EPSILON)
    {
        *tmin = tmin_numerator / direction;
        *tmax = tmax_numerator / direction;
    }
    else
    {
        *tmin = tmin_numerator * INFINITY;
        *tmax = tmax_numerator * INFINITY;
    }

    if (*tmin > *tmax)
    {
        temp = *tmin;
        *tmin = *tmax;
        *tmax = temp;
    }
}