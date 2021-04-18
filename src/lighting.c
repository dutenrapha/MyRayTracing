/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:57:48 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 00:32:57 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_color lighting(t_color a, t_material material,t_light light,t_tuple position,t_tuple eyev, t_tuple normalv, bool in_shadow)
{
	t_color ambient;
	t_color diffuse;
	t_color specular;
	t_color black;
	t_color effective_color;
	t_tuple lightv;
	t_tuple reflectv;
	float light_dot_normal;
	float reflect_dot_eye;
	float factor;

	black = color(0,0,0);
	effective_color = multicolor_v(material.color,light.intensity);
	lightv = normalize(sub(light.position,position));
	ambient = multicolor_s(effective_color,material.ambient);
	ambient = addcolor(ambient,a);
	light_dot_normal = dot(lightv, normalv);
	if(light_dot_normal < 0)
	{
		diffuse = black;
		specular = black;
	}
	else
	{
		diffuse = multicolor_s(effective_color,material.diffuse*light_dot_normal);
		reflectv = reflect(multi(lightv,-1), normalv);
		reflect_dot_eye = dot(reflectv, eyev);
		if (reflect_dot_eye <= 0)
		{
			specular = black;
		}
		else
		{
			factor  =  pow(reflect_dot_eye, material.shininess);
			specular = multicolor_s(light.intensity,material.specular*factor);
		}
	}
	if (in_shadow == true)
	{
		diffuse = black;
		specular = black;
	}
	return (addcolor(ambient,addcolor(diffuse,specular)));
}
