#include "../include/header.h"
#include <stdio.h>

t_projectile tick(t_enviroment env,t_projectile  proj)
{
	t_projectile resp;

	resp.position = add(proj.position, proj.velocity);
	resp.velocity = add(proj.velocity, add(env.gravity, env.wind));
	return resp;
}
