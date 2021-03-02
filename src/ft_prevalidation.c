#include "../include/header.h"

bool ft_prevalidation(int argc, char *argv[])
{
	char		*erro;
	erro = NULL;
	if (argc < 2)
	{
		erro = ft_error("001");
		ft_printf("%s\n", erro);
		return (true);
	}
	if (argc > 3)
	{
		erro = ft_error("002");
		ft_printf("%s\n", erro);
		return (true);
	}
	if (!is_rt_file(argv[1]))
	{
		erro = ft_error("003");
		ft_printf("%s\n", erro);
		return (true);
	}
	if (argc == 3 && ft_memcmp("--save",argv[2],7) != 0)
	{
		erro = ft_error("004");
		ft_printf("%s\n", erro);
		return (true);
	}
    return(false);
}