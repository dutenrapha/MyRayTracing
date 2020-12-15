#include "../include/header.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t j;
	size_t len_dst;

	len_dst = ft_strlen(dst);
	if (size <= len_dst)
	{
		return (size + ft_strlen((char *)src));
	}
	j = 0;
	while (*(src + j) != '\0' && len_dst < size - 1)
	{
		*(dst + len_dst) = *(src + j);
		len_dst++;
		j++;
	}
	*(dst + len_dst) = '\0';
	return (len_dst + ft_strlen(&src[j]));
}
