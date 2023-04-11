/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:43:45 by joowpark          #+#    #+#             */
/*   Updated: 2022/12/12 16:22:02 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "types.h"

# define BUFFER_SIZE 10
# define PATH_CH "./images/picachu.xpm"
# define PATH_WALL "./images/wall.xpm"
# define PATH_COLL "./images/ball.xpm"
# define PATH_EXIT "./images/exit.xpm"
# define PATH_GROUND "./images/ground.xpm"
# define TILE_SIZE 64
# define X_EVENT_KEY_EXIT 17
# define X_EVENT_KEY_DOWN 2
# define X_EVENT_KEY_UP 3
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define EXIT 1
# define RETURN 0
# define ON_DESTROY 17

int		ft_free_game_exit(struct s_game *g);
void	ft_free_fd_line(int fd, char *line);
void	ft_game_init(struct s_game *g);
int		ft_valid_map(struct s_map *m);
int		ft_parse_input(struct s_map *m, char *file);
void	ft_count(struct s_map *m, char *line);
void	ft_free(void **ptr, int end);
char	*get_next_line(int fd);
int		ft_game_set_init(struct s_game *g);
int		ft_render(struct s_game *g);
int		ft_free_game(struct s_game *g, int type);
int		ft_keys(int key, struct s_game *g);
int		ft_put_image(struct s_game *g, struct s_image *img, int x, int y);
void	ft_print_move(int nr_move);
#endif
