/*
** main.c for main in /home/descou_c/Graphic/raytracer2
**
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
**
** Started on  Wed Mar 29 10:30:38 2017 Charles Descoust
** Last update Sat May 27 12:55:59 2017 Bastien LECUSSAN
*/

#include "./inc/rt2.h"

int     display_help(char *bin)
{
  my_printf(1, 0, "USAGE\n\t%s file.conf | file.obj\n", bin);
  my_putstr("OBJECTS\n\tCONE | SPHERE | PLANE | STRIP | CYLINDER\n", 1);
  my_putstr("\tHYPERBOLOID1 | HYPERBOLOID2 | HYPERBOLOIC | ELLIPSOID | ", 1);
  my_putstr("PARABOLOID\n\n", 1);
  my_putstr("PROPERTIES\n\tOBJECT:string\n\tRADIUS:int\n\tPOSITION:float", 1);
  my_putstr(":float:float\n\tROTATION:float:float:float\n\tCOLOR:unsigned", 1);
  my_putstr(" char:unsigned char:unsigned char:unsigned char\n\t", 1);
  my_putstr("BRILLANCE:int 0 | 1\n\nOPTIONS\n\t", 1);
  my_putstr("PLANE:\n\t\tCHECKERBOARD:0 or 1\n\t", 1);
  my_putstr("HYPERBOLOID1, HYPERBOLOID2, ELLIPSOID, PARABOLOID, HYPERBOLO", 1);
  my_putstr("IC:\n\t\tCOEFS:float:float:float\n", 1);
  return (0);
}

int	call_function(int type, char **argv)
{
  if (type == MY_HELP)
    return (display_help(argv[0]));
  else if (type == MY_CONF)
    return (start_conf(argv[1]));
  else if (type == MY_OBJ)
    return (start_obj(argv));
  return (0);
}

int	main(int argc, char **argv, char **env)
{
  int	type;

  if (check_env(env) != 0)
    return (84);
  if (argc != 2)
    return (my_printf(2, 84, "Invalid number of arguments.\n"));
  if ((type = get_args_type(argv)) == -1)
    return (my_printf(2, 84, "Invalid argument.\n"));
  return (call_function(type, argv));
}
