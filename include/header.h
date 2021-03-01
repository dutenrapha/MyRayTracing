#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "../lib/mlx_linux/mlx.h"
#include "../lib/mlx_linux/mlx_int.h"
#include "../libft/libft.h"

#define EPSILON 0.00001
#define HEX_BASE		"0123456789abcdef"

typedef struct		s_bmpheader
{
	uint16_t		type;
	uint32_t		size;
	uint16_t		reserved;
	uint32_t		offset;
	uint32_t		dib_header_size;
	int32_t			width_px;
	int32_t			height_px;
	uint16_t		num_planes;
	uint16_t		bpp;
	uint32_t		compression;
	uint32_t		img_size_bytes;
	int32_t			x_resolution_ppm;
	int32_t			y_resolution_ppm;
	uint32_t		num_colors;
	uint32_t		important_colors;
}					t_bmpheader;

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
} t_tuple;

typedef struct s_projectile
{
	t_tuple	position;
	t_tuple	velocity;
} t_projectile;

typedef struct s_enviroment
{
        t_tuple	gravity;
        t_tuple	wind;
} t_enviroment;

typedef struct s_color
{
	float	red;
	float	green;
	float	blue;
} t_color;

typedef struct s_canvas
{
	int	width;
	int	height;
	t_color	**pixel;
} t_canvas;

typedef struct s_matrix
{
	float	**element;
	int dim;
} t_matrix;

typedef struct	s_ray
{
	t_tuple	origin;
	t_tuple	direction;
} t_ray;

typedef struct s_material
{
	t_color color;
	float   ambient;
	float   diffuse;
	float   specular;
	float   shininess;
} t_material;

typedef struct s_object
{
    int			id;
	char		*type;
	float		minimum;
    float		maximum;
	float		side;
    t_tuple		center;
	t_matrix	transform;
	t_material	material;
	bool		closed;
	t_tuple 	p1;
	t_tuple 	p2;
	t_tuple 	p3;
	t_tuple 	e1;
	t_tuple 	e2;
	t_tuple normal;
} t_object;

typedef struct s_intersection
{
	float		t;
	t_object	object;	
	bool		valid;
} t_intersection;

typedef struct s_comps
{
	float		t;
	t_object	object;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	bool		inside;
	t_tuple		over_point;
} t_comps;

typedef struct s_camera
{
	int		hsize;
	int		vsize;
	float		field_of_view;
	t_matrix	transform;
	float		half_width;
	float		half_height;
	float		pixel_size;
} t_camera;

typedef struct shape
{
	t_matrix	transform;
	t_material	material;
	t_ray		saved_ray;
} t_shape;

typedef struct	s_list
{
	t_intersection			content;
	struct s_list	*next;
}				t_list;

typedef struct s_objects
{
	t_object	content;
	struct s_objects *next;
} t_objects;

typedef struct s_light
{
	t_tuple position;
	t_color intensity;
} t_light;

typedef struct s_lights
{
	t_light	content;
	struct s_lights *next;
} t_lights;

typedef struct s_cameras
{
	t_camera	content;
	struct s_cameras *next;
} t_cameras;

typedef struct s_cv
{
	t_canvas	content;
	struct s_cv *next;
} t_cv;

typedef struct s_world
{
	t_lights	*lights;
	t_objects	*objects;
	t_color		ambient;
	bool		has_light;
	int		num_objects;
} t_world;


typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

// typedef struct  s_vars {
//         void    *mlx;
//         void    *win;
// }               t_vars;


typedef struct s_imgg
{
	t_data	content;
	struct s_imgg *next;
} t_imgg;

typedef struct s_config
{
	int			R_x;
	int			R_y;
	bool		save;
	t_color		A_color;
	t_cameras	*c_cameras;
	t_lights	*l_lights;
	t_objects	*o_objects;
	t_cv		*c_canvas;
	t_imgg		*img;
	t_imgg		*img_init;
	void    *mlx;
    void    *win;
} t_config;


void 	ft_setImg(t_config *config);

t_imgg	*ft_lstnew_img(t_data img);
int	ft_lstsize_img(t_imgg *img);
void	ft_lstclear_img(t_imgg **img);
void n_img(t_imgg **l, t_data img);

void ft_renderCamera(t_config config, bool save);

t_cv	*ft_lstnew_cv(t_canvas cv);
int	ft_lstsize_cv(t_cv *cv);
void	ft_lstclear_cv(t_cv **cv);
void cv(t_cv **l, t_canvas cv);

void	ft_canvas(t_config *config,t_world w);

void ft_init_world(t_world *w, t_config config);

void ft_readfile(t_config *config,char *argv[]);
bool	ft_checkSave(int argc);
bool	ft_prevalidation(int argc, char *argv[]);

int ft_resizeColor(float a);
unsigned long createRGB(int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_save(t_config	config, t_data mlx, int tag);

t_matrix rotation(t_tuple normal);
t_object square(int id);
void light_a(t_world *w, t_light light);


float	ft_atof(const char *nptr);

t_matrix view_transform(t_tuple from,t_tuple forward,t_tuple up);

char	*ft_error(char* error);
void	ft_conf(t_config **config, char *line,int tag);
void	ft_assign_R(t_config *config, char *R_x, char *R_y);
void	ft_assign_A(t_config *config, char *A_ratio, char *A_light);
void	ft_assign_l(t_config *config, char *position, char *brightness, char *cor);
void	ft_assign_c(t_config *config, char *position, char *normal, char *FOV);
void	ft_assign_pl(t_config *config, char *position, char *normal, char *cor,int tag);
void	ft_assign_sp(t_config *config, char *position, char *diameter, char *cor,int tag);
void	ft_assign_sq(t_config *config, char *position, char *normal, char *size, char *cor,int tag);
void	ft_assign_cy(t_config *config, char *position, char *normal, char *diameter, char *height, char *cor,int tag);
void	ft_assign_tr(t_config *config, char *p1, char *p2, char *p3, char *cor);

t_objects	*ft_lstnew_o(t_object content);
int	ft_lstsize_o(t_objects *lst);
void	ft_lstclear_o(t_objects **lst);
void objects(t_objects **l, t_object light);

t_cameras	*ft_lstnew_c(t_camera content);
int	ft_lstsize_c(t_cameras *lst);
void	ft_lstclear_c(t_cameras **lst);
void cameras(t_cameras **l, t_camera c);

t_list	*ft_lstnew(t_intersection content);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

t_intersection hit(t_list *xs);
t_color  color_at(t_world world, t_ray ray);
t_list	*intersect_world(t_world w, t_ray r);
t_list	*intersect(t_object s, t_ray ray);
t_list	*intersect_caps(t_object cyl, t_ray r);
void bubbleSort(t_list **xs);
t_color shade_hit(t_world world,t_comps comps);

t_objects	*ft_lstnew_w(t_object content);
int	ft_lstsize_w(t_objects *lst);
void	ft_lstclear_w(t_objects **lst);

void world(t_world *w, t_object content);

t_lights	*ft_lstnew_l(t_light content);
int	ft_lstsize_l(t_lights *lst);
void	ft_lstclear_l(t_lights **lst);

void light(t_lights **l, t_light light);


bool is_shadowed(t_light light, t_world world, t_tuple point);

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

t_matrix matrix(int dim);
void freeMatrix(t_matrix *A);
void writeMatrix(t_matrix *m, int i, int j, float e);
bool isMatrixEqual(t_matrix A, t_matrix B);
t_matrix matrixMulti(t_matrix A, t_matrix B);
t_tuple matrixMultiVec(t_matrix A, t_tuple b);
t_matrix identity();
t_matrix transpose(t_matrix A);
t_matrix submatrix(t_matrix A, int i, int j);
float minor_op(t_matrix A, int i, int j);
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
t_ray ray(t_tuple origin, t_tuple direction);
t_tuple position(t_ray ray,float t);
t_object sphere(int id);
t_intersection intersection(float t, t_object o);
t_ray	transform(t_ray r,t_matrix m);
void	set_transform(t_object *s,t_matrix m);
t_tuple	normal_at(t_object o,t_tuple v);
t_tuple reflect(t_tuple in, t_tuple normal);
t_light point_light(t_tuple position, t_color intensity);
t_material material();
t_color lighting(t_color a,t_material material,t_light light,t_tuple position,t_tuple eyev, t_tuple normalv, bool in_shadow);
t_comps prepare_computations(t_intersection i, t_ray r);

t_camera camera(int hsize,int vsize,float field_of_view);
t_ray ray_for_pixel(t_camera camera,float px,float py);
t_canvas render(t_camera camera,t_world world);
void copyMatrix(t_matrix *d, t_matrix o);
t_shape	test_shape();
void    set_transform_2(t_shape *s,t_matrix m);
void	intersect_2(t_shape *s,t_ray ray);
t_tuple	normal_at_2(t_shape s, t_tuple p);
t_tuple local_normal_at(t_object o,t_tuple local_point);
t_object plan();
t_object cube(int id);
void	check_axis(float origin, float direction, float *tmin,float *tmax);
t_object cylinder(int id);
t_object	triangle(int id, t_tuple p1,t_tuple p2,t_tuple p3);

void    ft_split_free(char ***split);