#include "../include/header.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*pointer;

	pointer = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		*(pointer + i) = (unsigned char)c;
		i++;
	}
	return (str);
}
