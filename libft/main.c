#include "../include/libft.h"

int main()
{
	char **all_lines;
	int n_lines = ft_get_all_lines("../maps/test_maps/elem.fdf", &all_lines);
	if (!all_lines) return -1;
	ft_printf(2, "porca madonna %d\n", n_lines);
	for(int i = 0; i < n_lines; i++)
		ft_printf(1,"<%s>\n", all_lines[i]);
	ft_printf(2, "porca madonna\n");
	for(int i = 0; i < n_lines; i++)
		free(all_lines[i]);
	ft_printf(2, "porca madonna\n");
	free(all_lines);
}