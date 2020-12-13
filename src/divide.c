#include "../include/header.h"

t_tuple divide(t_tuple v1, float a)
{
        t_tuple v2;

        v2.x = v1.x / a;
        v2.y = v1.y / a;
        v2.z = v1.z / a;
        v2.w = v1.w / a;

        return v2;
}
