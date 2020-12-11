#include <stdbool.h>
#include <math.h>
#define EPSILON 0.00001

typedef struct s_tuple
{
	float x;
	float y;
	float z;
	float w;
} t_tuple;

typedef struct s_projectile
{
	t_tuple position;
	t_tuple velocity;
} t_projectile;

typedef struct s_enviroment
{
        t_tuple gravity;
        t_tuple wind;
} t_enviroment;

typedef struct s_color
{
	float red;
	float green;
	float blue;
} t_color;

t_tuple	point(float x, float y, float z);
t_tuple vector(float x, float y, float z);
bool isEqual(t_tuple v1, t_tuple v2);
t_tuple add(t_tuple v1, t_tuple v2);
t_tuple sub(t_tuple v1, t_tuple v2);
t_tuple negate(t_tuple v1);
t_tuple multi(t_tuple v1, float a);
t_tuple div(t_tuple v1, float a);
float magnitude(t_tuple v1);
t_tuple normalize(t_tuple v1);
float dot(t_tuple v1, t_tuple v2);
t_tuple cross(t_tuple v1, t_tuple v2);
t_projectile tick(t_enviroment env,t_projectile  proj);
t_color color(float r, float g, float b);
