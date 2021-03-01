#include "../include/header.h"

void	ft_conf(t_config **config, char *line,int tag)
{
    char	**line_t;
    
    line_t	= ft_split(line,' ');
    if (ft_memcmp("R",line_t[0],2) == 0)
        ft_assign_R(*config,line_t[1],line_t[2]);
    if (ft_memcmp("A",line_t[0],2) == 0)
        ft_assign_A(*config, line_t[1],line_t[2]);
    if (ft_memcmp("c",line_t[0],2) == 0)
        ft_assign_c(*config, line_t[1],line_t[2],line_t[3]);
    if (ft_memcmp("l",line_t[0],2) == 0)
        ft_assign_l(*config, line_t[1],line_t[2],line_t[3]);
    if (ft_memcmp("pl",line_t[0],3) == 0)
        ft_assign_pl(*config, line_t[1],line_t[2],line_t[3],tag);
    if (ft_memcmp("sp",line_t[0],3) == 0)
        ft_assign_sp(*config, line_t[1],line_t[2],line_t[3],tag);
    if (ft_memcmp("sq",line_t[0],3) == 0)
        ft_assign_sq(*config, line_t[1],line_t[2],line_t[3], line_t[4],tag);
    if (ft_memcmp("cy",line_t[0],3) == 0)
        ft_assign_cy(*config, line_t[1],line_t[2],line_t[3], line_t[4], line_t[5],tag);
    if (ft_memcmp("tr",line_t[0],3) == 0)
        ft_assign_tr(*config, line_t[1],line_t[2],line_t[3], line_t[4]);
    ft_split_free(&line_t);
}