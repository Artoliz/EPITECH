/*
** env_args.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/args
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Tue May  2 21:46:57 2017 Charles Aubert
** Last update Fri May 26 12:15:13 2017 Charles Aubert
*/

#include "../inc/args.h"

int     check_env(char **env)
{
  int   i;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_strcmp(env[i], "DISPLAY=:0") == 0)
        return (0);
      i += 1;
    }
  return (my_printf(2, 84, "Segmentation...Euh? Non!\n"));
}

int	get_args_type(char **argv)
{
  int	res;

  res = -1;
  if (my_strcmp(argv[1], "-h") == 0 || my_strcmp(argv[1], "--help") == 0)
    res = MY_HELP;
  else if (my_contain(argv[1], STR_CONF,
		     my_strlen(argv[1]) - my_strlen(STR_CONF) - 1) == 0)
    res = MY_CONF;
  else if (my_contain(argv[1], STR_OBJ,
		     my_strlen(argv[1]) - my_strlen(STR_OBJ) - 1) == 0)
    res = MY_OBJ;
  return (res);
}
