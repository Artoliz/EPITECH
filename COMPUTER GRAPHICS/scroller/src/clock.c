/*
** clock.c for  in /home/Gxan/delivery/scroller/src
** 
** Made by Amardeilh Guilhem
** Login   <Gxan@epitech.net>
** 
** Started on  Sat Apr  1 20:40:16 2017 Amardeilh Guilhem
** Last update Sun Apr  2 17:17:45 2017 Amardeilh Guilhem
*/

#include "../inc/my.h"

t_oki           *start_clock()
{
  t_oki         *time;

  if ((time = malloc(sizeof(struct s_oki))) == NULL)
    return (NULL);
  if ((clock_getres(CLOCK_REALTIME, &(time->tp))) == -1)
    return (NULL);
  clock_gettime(CLOCK_REALTIME, &(time->tp));
  time->start = time->tp.tv_sec;
  return (time);
}
