#include "../include/header.h"

t_tuple reflect(t_tuple in, t_tuple normal)
{
 	return (sub(in,multi(normal,2*dot(in,normal))));	
}
