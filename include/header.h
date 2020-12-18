#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
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

typedef struct s_canvas
{
	int width;
	int height;
	t_color **pixel;
} t_canvas;

typedef struct s_matrix
{
	float **element;
	int dim;
} t_matrix;

t_tuple	point(float x, float y, float z);
t_tuple vector(float x, float y, float z);
bool isEqual(t_tuple v1, t_tuple v2);
t_tuple add(t_tuple v1, t_tuple v2);
t_tuple sub(t_tuple v1, t_tuple v2);
t_tuple negate(t_tuple v1);
t_tuple multi(t_tuple v1, float a);
t_tuple divide(t_tuple v1, float a);
float magnitude(t_tuple v1);
t_tuple normalize(t_tuple v1);
float dot(t_tuple v1, t_tuple v2);
t_tuple cross(t_tuple v1, t_tuple v2);
t_projectile tick(t_enviroment env,t_projectile  proj);
t_color color(float r, float g, float b);
t_color addcolor(t_color c1, t_color c2);
t_color subcolor(t_color c1, t_color c2);
t_color multicolorS(t_color c1, float a);
t_color multicolorV(t_color c1, t_color c2);
bool isColorEqual(t_color c1, t_color c2);
t_canvas canvas(int w, int h);
void writePixel(t_canvas *cv, int w, int h, t_color c);
char *canvas_to_ppm(t_canvas *cv);
t_matrix matrix(int dim);
void freeMatrix(t_matrix A);
void writeMatrix(t_matrix *m, int i, int j, float e);
bool isMatrixEqual(t_matrix A, t_matrix B);
t_matrix matrixMulti(t_matrix A, t_matrix B);
t_tuple matrixMultiVec(t_matrix A, t_tuple b);
t_matrix identity();
t_matrix transpose(t_matrix A);
t_matrix submatrix(t_matrix A, int i, int j);
float minor(t_matrix A, int i, int j);
float cofactor(t_matrix A, int i, int j);
float det(t_matrix A);
bool isInvertible(t_matrix A);
t_matrix inverse(t_matrix A);
t_matrix translation(float x, float y, float z);
t_matrix scaling(float x, float y, float z);
t_matrix rotation_x(float r);
t_matrix rotation_y(float r);
t_matrix rotation_z(float r);
t_matrix shearing(float xy, float xz, float yx,float yz, float zx, float zy);
