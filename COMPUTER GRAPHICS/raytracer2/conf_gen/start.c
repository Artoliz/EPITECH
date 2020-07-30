/*
** start.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/conf_gen
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Tue May  2 21:31:02 2017 Charles Aubert
** Last update Sun May 28 22:53:19 2017 Charles Aubert
*/

#include "../inc/rt2.h"

t_objects	create_func_prep(t_objects tools)
{
  tools.func[0] = sphere_prep;
  tools.func[1] = cone_prep;
  tools.func[2] = cylinder_prep;
  tools.func[3] = strip_prep;
  tools.func[4] = paraboloid_prep;
  tools.func[7] = ellipsoid_prep;
  tools.func[8] = sphere_prep;
  tools.func[6] = hyperboloid1_prep;
  tools.func[5] = hyperboloid2_prep;
  return (tools);
}

int     my_free_conf(sfVector2i *pos_min, sfVector2i *pos_max,
                     t_object ***objs)
{
  free(pos_min);
  free(pos_max);
  free_list_objects(objs[0]);
  free_list_objects(objs[1]);
  free_list_objects(objs[2]);
  free_list_objects(objs[3]);
  return (0);
}

int             start_conf(char *name)
{
  t_object      ***objs;
  t_win         win;
  sfVector2i    *pos_min;
  sfVector2i    *pos_max;

  if (check_win((win = create_win_struct("Raytracer2", WIDTH, HEIGHT))) != 0)
    return (84);
  if ((objs = malloc(sizeof(t_object**) * 4)) == NULL)
    return (84);
  if ((objs[0] = create_objects_from_file(name)) == NULL)
    return (my_printf(2, 84, "An error occured while loading the file.\n"));
  if ((objs[1] = create_objects_from_file(name)) == NULL)
    return (my_printf(2, 84, "An error occured while loading the file.\n"));
  if ((objs[2] = create_objects_from_file(name)) == NULL)
    return (my_printf(2, 84, "An error occured while loading the file.\n"));
  if ((objs[3] = create_objects_from_file(name)) == NULL)
    return (my_printf(2, 84, "An error occured while loading the file.\n"));
  if ((pos_min = init_pos_min()) == NULL)
    return (84);
  if ((pos_max = init_pos_max()) == NULL)
    return (84);
  if (multi_threads(win, pos_min, pos_max, objs) == 84)
    return (84);
  my_free_conf(pos_min, pos_max, objs);
  return (0);
}
