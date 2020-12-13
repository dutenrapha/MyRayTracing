#include "../include/header.h"

size_t	ft_strlen(const char *s)
{
	return (!*s ? 0 : ft_strlen(s + 1) + 1);
}
