/*
** main.c for main.c in /home/cedric/delivery/ex
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Oct 22 10:31:05 2016 Cédric Thomas
** Last update Wed Dec  7 21:42:07 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include "wireframe.h"
#include "my.h"

void		connect_mod_vertex(t_vertex **ll, sfVector2i dim, int mod)
{
  int		i;
  t_vertex	*head;
  t_vertex	*tail;
  t_vertex	*swap;

  i = 0;
  head = *ll;
  tail = *ll;
  while (i < dim.y * dim.x)
    {
      if (i % dim.x == mod && i >= dim.x)
	put_vertex(&(tail->linked), head->point, 0);
      if (i >= dim.x)
	tail = tail->next;
      head = head->next;
      i += 1;
    }
}

int		main(int ac, char **av)
{
  t_vertex	*top;
  t_vertex	*bot;
  sfVector2i	dim;

  if (ac != 2)
    return (84);
  dim = wireparse(&bot, &top, av[1]);
  if (dim.x == -1)
    return (84);
  set_vertex_position(&bot, &top, dim);
  draw_this(&bot, &top, dim);
  free_vertex(&top, 1);
  free_vertex(&bot, 1);
}
