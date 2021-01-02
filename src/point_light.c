#include "../include/header.h"

t_light point_light(t_tuple position, t_color intensity)
{
	t_light	resp;
	
	resp.position = position;
	resp.intensity = intensity;
	return (resp);
}
