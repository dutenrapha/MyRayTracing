#include "../include/header.h"

bool	is_valid(char *line)
{
    char	**line_t;
    bool    resp;

    resp = false;
    line_t	= ft_split(line,' ');
    if (ft_memcmp("R",line_t[0],2) == 0)
        resp = ft_validate_r(line_t);
    else if (ft_memcmp("A",line_t[0],2) == 0)
        resp = ft_validate_a(line_t);
    else if (ft_memcmp("c",line_t[0],2) == 0)
        resp = ft_validate_c(line_t);
    else if (ft_memcmp("l",line_t[0],2) == 0)
        resp = ft_validate_l(line_t);
    else if (ft_memcmp("pl",line_t[0],3) == 0)
        resp = ft_validate_pl(line_t);
    else if (ft_memcmp("sp",line_t[0],3) == 0)
        resp = ft_validate_sp(line_t);
    else if (ft_memcmp("sq",line_t[0],3) == 0)
        resp = ft_validate_sq(line_t);
    else if (ft_memcmp("cy",line_t[0],3) == 0)
        resp = ft_validate_cy(line_t);
    else if (ft_memcmp("tr",line_t[0],3) == 0)
        resp = ft_validate_tr(line_t);
    else
        ft_printf("Error!\nCodigo nao valido!\nOs codigos validos sao: R, A, c, l, pl, sp, sq, cy e tr");
    ft_split_free(&line_t);
    return (resp);
}
