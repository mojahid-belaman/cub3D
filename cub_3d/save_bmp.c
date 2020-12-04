/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:34:49 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/21 13:34:59 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_fh_fih(t_bmp *bmp, t_var *var)
{
	bmp->width = var->map.resol_w;
	bmp->height = var->map.resol_h;
	bmp->bit_count = 24;
	bmp->width_in_bytes = ((bmp->width * bmp->bit_count + 31) / 32) * 4;
	bmp->img_size = bmp->width_in_bytes * bmp->height;
	bmp->bi_size = 40;
	bmp->bmf_offbits = 54;
	bmp->filesize = 54 + bmp->img_size;
	bmp->bit_planes = 1;
	ft_memcpy(bmp->header, "BM", 2);
	ft_memcpy(bmp->header + 2, &bmp->filesize, 4);
	ft_memcpy(bmp->header + 10, &bmp->bmf_offbits, 4);
	ft_memcpy(bmp->header + 14, &bmp->bi_size, 4);
	ft_memcpy(bmp->header + 18, &bmp->width, 4);
	ft_memcpy(bmp->header + 22, &bmp->height, 4);
	ft_memcpy(bmp->header + 26, &bmp->bit_planes, 2);
	ft_memcpy(bmp->header + 28, &bmp->bit_count, 2);
	ft_memcpy(bmp->header + 34, &bmp->img_size, 4);
}

void	save_bmp(unsigned char *buf, t_bmp *bmp, t_var *var)
{
	int i;
	int j;

	bmp->row = bmp->height - 1;
	bmp->col = 0;
	i = 0;
	while (bmp->row >= 0)
	{
		j = 0;
		bmp->col = 0;
		while (bmp->col < bmp->width)
		{
			bmp->color = var->texture[bmp->row * var->map.resol_w + bmp->col];
			bmp->r = (bmp->color >> 16);
			bmp->g = (bmp->color >> 8);
			bmp->b = bmp->color;
			buf[i * bmp->width_in_bytes + j * 3 + 0] = bmp->b;
			buf[i * bmp->width_in_bytes + j * 3 + 1] = bmp->g;
			buf[i * bmp->width_in_bytes + j * 3 + 2] = bmp->r;
			j++;
			bmp->col++;
		}
		i++;
		bmp->row--;
	}
}

void	draw_in_file(t_var *var)
{
	int				fd;
	unsigned char	*buf;
	t_bmp			bmp;

	var->save = 0;
	if ((fd = open("screenshot.bmp", O_RDWR | O_CREAT, 00700)) == -1)
		hundle_error(BMP_FILE_ERR, var);
	bmp.header = ft_calloc(54, sizeof(unsigned char));
	init_fh_fih(&bmp, var);
	buf = (unsigned char *)malloc(bmp.img_size * sizeof(unsigned char));
	save_bmp(buf, &bmp, var);
	write(fd, bmp.header, 54);
	write(fd, buf, bmp.img_size);
	free(buf);
	ft_putstr_fd("Save success !\n", 1);
	close(fd);
	exit(0);
}
