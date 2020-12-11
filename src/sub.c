#include "../include/header.h"

t_tuple sub(t_tuple v1, t_tuple v2)
{
        t_tuple v3;

        v3.x = v1.x - v2.x;
        v3.y = v1.y - v2.y;
        v3.z = v1.z - v2.z;
        v3.w = v1.w - v2.w;

        return v3;
}
