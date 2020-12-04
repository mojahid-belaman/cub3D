/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:31:38 by mbelaman          #+#    #+#             */
/*   Updated: 2020/11/21 13:31:49 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		hundle_key(t_var *var)
{
	if (var->up == 1)
		move_up(var);
	if (var->down == 1)
		move_down(var);
	if (var->right == 1)
		move_right(var);
	if (var->left)
		move_left(var);
	if (var->rt_r == 1)
		rotation_right(var);
	if (var->rt_l == 1)
		rotation_left(var);
	return (0);
}

int		key_press(int key, t_var *var)
{
	if (key == KEY_UP)
		var->up = 1;
	if (key == KEY_DOWN)
		var->down = 1;
	if (key == KEY_RIGHT)
		var->right = 1;
	if (key == KEY_LEFT)
		var->left = 1;
	if (key == KEY_R_R)
		var->rt_r = 1;
	if (key == KEY_R_L)
		var->rt_l = 1;
	if (key == EXIT_KEY)
		hundle_error(END_GAME, var);
	return (0);
}

int		key_release(int key, t_var *var)
{
	if (key == KEY_UP)
		var->up = 0;
	if (key == KEY_DOWN)
		var->down = 0;
	if (key == KEY_RIGHT)
		var->right = 0;
	if (key == KEY_LEFT)
		var->left = 0;
	if (key == KEY_R_R)
		var->rt_r = 0;
	if (key == KEY_R_L)
		var->rt_l = 0;
	if (key == EXIT_KEY)
		hundle_error(END_GAME, var);
	return (0);
}

int		exit_win(t_var *var)
{
	hundle_error(END_GAME, var);
	return (0);
}
