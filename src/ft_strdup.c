#include "../include/header.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s;

	i = -1;
	if (!s1 || !(s = malloc((ft_strlen(s1) + 1) * sizeof(*s))))
		return (NULL);
	while (s1[++i])
		s[i] = s1[i];
	s[i] = '\0';
	return (s);
}
