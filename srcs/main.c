/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: seojepar <seojepar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/18 14:34:44 by seojepar		  #+#	#+#			 */
/*   Updated: 2024/11/28 13:01:00 by seojepar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

void	check_format(int ac, char *av[])
{
	int	fd;

	if (ac != 2)
		xerr("Wrong number of arguments");
	else if (!ft_endswith(av[1], ".cub"))
		xerr("The file must have a .cub extension");
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			xerr(strerror(errno));
		else
		{
			close(fd);
			return ;
		}
	}
	exit(1);
}

int	free_cub(t_info *cub)
{
	int	i;

	i = 0;
	while (i < ID_NUM)
	{
		if (cub->fill[i])
			free(cub->fill[i]);
		i++;
	}
	i = 0;
	if (!cub->map)
		return (0);
	while (i < cub->h)
	{
		if (cub->map[i])
			free(cub->map[i]);
		i++;
	}
	free(cub);
	free(cub->map);
	return (0);
}

t_info	*init_cub(void)
{
	int		id;
	void	*ptr;
	t_info	*cub;

	cub = ft_calloc(sizeof(t_info));
	cub->mlx = mlx_init();
	id = NO;
	while (id < ID_NUM)
	{
		if (is_texture_id(id))
			ptr = malloc(sizeof(t_text));
		else if (is_color_id(id))
			ptr = malloc(sizeof(unsigned int));
		if (!ptr)
		{
			free_cub(cub);
			exit(1);
		}
		cub->fill[id] = ptr;
		id++;
	}
	return (cub);
}

void	init_mlx(t_info *cub)
{
	cub->win = mlx_new_window(cub->mlx, SCREEN_W, SCREEN_H, "cub3d");
	cub->img = mlx_new_image(cub->mlx, SCREEN_W, SCREEN_H);
	cub->data = mlx_get_data_addr(cub->img, &cub->bpp, \
	&cub->size_line, &cub->endian);
	cub->pos.x += 0.5;
	cub->pos.y += 0.5;
}

int	main(int ac, char *av[])
{
	t_info	*cub;

	check_format(ac, av);
	cub = init_cub();
	parse(cub, av[1]);
	init_mlx(cub);
	render(cub);
	events(cub);
}
