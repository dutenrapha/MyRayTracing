
#include "../include/header.h"

int	ft_strDlen(char **s)
{
	int len;
	
	if (!s)
		return (0);
	len = 0;
	while (*s++)
	{
		len++;
	}
	return (len);
}
