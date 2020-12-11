#include "../include/header.h"
#include <stdio.h>

bool isEqual(t_tuple v1, t_tuple v2)
{
	if (fabs(v1.x - v2.x) > EPSILON)
	{
		return false;
	}
	else if (fabs(v1.y - v2.y) > EPSILON)
	{        
        	return false;
	}        
	else if (fabs(v1.z - v2.z) > EPSILON)
	{
	 	return false;
	}
        else if (fabs(v1.w - v2.w) > EPSILON)
	{
		return false;
	}
	else
	{
		return true;
	}
}
