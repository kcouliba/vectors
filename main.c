/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouliba <kcouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 16:17:38 by kcouliba          #+#    #+#             */
/*   Updated: 2015/06/09 22:07:49 by kcouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <vector.h>

#define MAPSIZE     12
#define WALLSIZE    64
#define SIZE        WALLSIZE * MAPSIZE
#define STEP        WALLSIZE / 2
#define NORTH       0
#define SOUTH       1
#define EAST        2
#define WEST        3

void	print_vector(t_vector2d u)
{
	printf("[%f][%f]", u.x, u.y);
}

size_t	wall_collision(t_vector2d *player, t_vector2d next_pos)
{
	t_vector2d	collision;
	t_vector2d	coord;
	t_vector2d	oob;

	coord.x = (int)(next_pos.x / WALLSIZE);
	coord.y = (int)(next_pos.y / WALLSIZE);
	printf("coord : ");
	print_vector(coord);
	printf("\n");
	collision.x = (((size_t)coord.x <= 0) || ((size_t)coord.x >= MAPSIZE)) ? 1 : 0;
	collision.y = (((size_t)coord.y <= 0) || ((size_t)coord.y >= MAPSIZE)) ? 1 : 0;
	if ((next_pos.x - player->x) > 0)
		oob.x = ((size_t)collision.x) ? coord.x * WALLSIZE - 1 : next_pos.x;
	else
		oob.x = ((size_t)collision.x) ? (coord.x + 1) * WALLSIZE + 1 : next_pos.x;
	if ((next_pos.y - player->y) > 0)
		oob.y = ((size_t)collision.y) ? coord.y * WALLSIZE - 1 : next_pos.y;
	else
		oob.y = ((size_t)collision.y) ? (coord.y + 1) * WALLSIZE + 1 : next_pos.y;
	printf("collision : ");
	print_vector(collision);
	printf("\n");
	printf("wall oob : ");
	print_vector(oob);
	printf("\n");
	*player = vector2d_sub(next_pos, vector2d_sub(next_pos, oob));
	return ((size_t)collision.x || (size_t)collision.y);
}

void	move(t_vector2d *player_pos, double stepx, double stepy, double way)
{
	t_vector2d	next_player_pos;

	next_player_pos = vector2d_add_scal(*player_pos, STEP * stepx * way, STEP * stepy * way);
	printf("next player position : ");
	print_vector(next_player_pos);
	printf("\n");
	if (!wall_collision(player_pos, next_player_pos))
		move(player_pos, stepx, stepy, way);
	else
	{
		printf("final player position : ");
		print_vector(*player_pos);
		printf("\n\n");
	}
}

int		main(void)
{
	t_vector2d	player_pos;

	player_pos.x = SIZE / 2 + WALLSIZE / 2;
	player_pos.y = SIZE / 2 + WALLSIZE / 2;
	printf("player position : ");
	print_vector(player_pos);
	printf("\n");
	move(&player_pos, 1, .95, -1);
	printf("player position : ");
	print_vector(player_pos);
	printf("\n");
	move(&player_pos, .95, 1, 1);
	return (0);
}
