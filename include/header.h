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

typedef struct s_iter
{
	int		i;
	int		j;
	bool	swapped;
	int		n;
} t_iter;

typedef struct s_par
{
	char	*position;
	char	*normal;
	char	*diameter;
	char	*height;
	char	*cor;
} t_par;

typedef struct s_par2
{
	char	*size;
	char	*cor;
} t_par2;

typedef struct s_par3
{
	char	*p1;
	char	*p2;
	char	*p3;
} t_par3;

typedef struct s_par4
{
	double	val;
	int		flag;
} t_par4;

typedef struct s_par5
{
	int yy;
	int xx;
} t_par5;

typedef struct s_par6
{
	int i;
	int j;
} t_par6;

typedef struct s_par7
{
	float distance;
	t_tuple direction;
} t_par7;

typedef struct s_par8
{
	t_ray	r;
	float	xoffset;
	float	yoffset;
	float	world_x;
	float	world_y;
} t_par8;

typedef struct s_par9
{
	t_tuple		forward;
	t_tuple		upn;
	t_tuple		left;
	t_tuple		true_up;
} t_par9;





void	init_iter(t_iter *p,t_list *xs);

bool is_normal(char *s);
bool is_num(char *s);
bool is_coordenada(char *s);
bool is_color(char *s);
int	ft_str_dlen(char **s);

 bool	ft_validate_r(char **line_t);
 bool	ft_validate_a(char **line_t);
 bool	ft_validate_c(char **line_t);
 bool	ft_validate_l(char **line_t);
 bool	ft_validate_pl(char **line_t);
 bool	ft_validate_sp(char **line_t);
 bool	ft_validate_sq(char **line_t);
 bool	ft_validate_cy(char **line_t);
 bool	ft_validate_tr(char **line_t);


bool	is_valid(char *line);

bool	is_rt_file(char *file);

void	ft_set_img(t_config *config);

t_imgg	*ft_lstnew_img(t_data img);
int	ft_lstsize_img(t_imgg *img);
void	ft_lstclear_img(t_imgg **img);
void n_img(t_imgg **l, t_data img);

void ft_render_camera(t_config config, bool save);

t_cv	*ft_lstnew_cv(t_canvas cv);
int	ft_lstsize_cv(t_cv *cv);
void	ft_lstclear_cv(t_cv **cv);
void cv(t_cv **l, t_canvas cv);

void	ft_canvas(t_config *config,t_world w);

void ft_init_world(t_world *w, t_config config);

bool ft_readfile(t_config *config,char *argv[]);
bool	ft_checksave(int argc);
bool	ft_prevalidation(int argc, char *argv[]);

int ft_resize_color(float a);
unsigned long create_rgb(int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	ft_save(t_config config);

t_matrix rotation(t_tuple normal);
t_object square(void);
void light_a(t_world *w, t_light light);


float	ft_atof(const char *nptr);

t_matrix view_transform(t_tuple from,t_tuple forward,t_tuple up);

char	*ft_error(char* error);
void	ft_conf(t_config **config, char *line);
void	ft_assign_r(t_config *config, char *r_x, char *r_y);
void	ft_assign_a(t_config *config, char *a_ratio, char *a_light);
void	ft_assign_l(t_config *config, char *ps, char *brightness, char *cor);
void	ft_assign_c(t_config *config, char *position, char *normal, char *fov);
void	ft_assign_pl(t_config *config, char *ps, char *n, char *cor);
void	ft_assign_sp(t_config *config, char *p, char *d, char *cor);
void	ft_assign_sq(t_config *config, char *ps, char *n, t_par2 p);
void	ft_assign_cy(t_config *config, t_par p);
void	ft_assign_tr(t_config *config, t_par3 po, char *cor);

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
void bubblesort(t_list **xs);
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
bool is_equal(t_tuple v1, t_tuple v2);
t_tuple add(t_tuple v1, t_tuple v2);
t_tuple sub(t_tuple v1, t_tuple v2);
t_tuple negate(t_tuple v1);
t_tuple multi(t_tuple v1, float a);
t_tuple divide(t_tuple v1, float a);
float magnitude(t_tuple v1);
t_tuple normalize(t_tuple v1);
float dot(t_tuple v1, t_tuple v2);
t_tuple cross(t_tuple v1, t_tuple v2);

t_color color(float r, float g, float b);
t_color addcolor(t_color c1, t_color c2);
t_color subcolor(t_color c1, t_color c2);
t_color multicolor_s(t_color c1, float a);
t_color multicolor_v(t_color c1, t_color c2);
bool is_color_equal(t_color c1, t_color c2);
t_canvas canvas(int w, int h);
void write_pixel(t_canvas *cv, int w, int h, t_color c);

t_matrix matrix(int dim);
void free_matrix(t_matrix *a);
void write_matrix(t_matrix *m, int i, int j, float e);
bool is_matrix_equal(t_matrix a, t_matrix b);
t_matrix matrix_multi(t_matrix a, t_matrix b);
t_tuple matrix_multi_vec(t_matrix a, t_tuple b);
t_matrix identity(void);
t_matrix transpose(t_matrix a);
t_matrix submatrix(t_matrix a, int i, int j);
float minor_op(t_matrix a, int i, int j);
float cofactor(t_matrix a, int i, int j);
float det(t_matrix a);
bool is_invertible(t_matrix A);
t_matrix inverse(t_matrix a);
t_matrix translation(float x, float y, float z);
t_matrix scaling(float x, float y, float z);
t_matrix rotation_x(float r);
t_matrix rotation_y(float r);
t_matrix rotation_z(float r);
t_ray ray(t_tuple origin, t_tuple direction);
t_tuple position(t_ray ray,float t);
t_object sphere(void);
t_intersection intersection(float t, t_object o);
t_ray	transform(t_ray r,t_matrix m);
void	set_transform(t_object *s,t_matrix m);
t_tuple	normal_at(t_object o,t_tuple v);
t_tuple reflect(t_tuple in, t_tuple normal);
t_light point_light(t_tuple position, t_color intensity);
t_material material(void);
t_color lighting(t_color a,t_material material,t_light light,t_tuple position,t_tuple eyev, t_tuple normalv, bool in_shadow);
t_comps prepare_computations(t_intersection i, t_ray r);

t_camera camera(int hsize,int vsize,float field_of_view);
t_ray ray_for_pixel(t_camera camera,float px,float py);
t_canvas render(t_camera camera,t_world world);
void copy_matrix(t_matrix *d, t_matrix o);
t_shape	test_shape(void);
void    set_transform_2(t_shape *s,t_matrix m);
void	intersect_2(t_shape *s,t_ray ray);
t_tuple	normal_at_2(t_shape s, t_tuple p);
t_tuple local_normal_at(t_object o,t_tuple local_point);
t_object plan(void);
t_object cube(int id);
void	check_axis(float origin, float direction, float *tmin,float *tmax);
t_object cylinder(void);
t_object	triangle(int id, t_tuple p1,t_tuple p2,t_tuple p3);

void    ft_split_free(char ***split);
