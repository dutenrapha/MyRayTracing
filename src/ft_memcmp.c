#include "../include/header.h"

static	int	ft_strlen(const char *s)
{
	int len;

	len = 0;
	if (s == NULL)
		return (len);
	while (*s++)
	{
		len++;
	}
	return (len);
}



int	ft_memcmp(const void *str1, const void *str2)
{
	int			i;
	int 			n;
	unsigned char	*string1;
	unsigned char	*string2;

	n = ft_strlen(str1);
	string1 = (unsigned char *)str1;
	string2 = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (*(string1 + i) != *(string2 + i))
		{
			return (*(string1 + i) - *(string2 + i));
		}
		i++;
	}
	return (0);
}
