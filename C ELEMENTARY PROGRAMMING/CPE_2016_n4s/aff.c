/*
** aff.c for aff in /home/descou_c/CPE/CPE_2016_n4s
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue May 16 11:32:41 2017 Charles Descoust
** Last update Tue May 16 11:33:37 2017 Charles Descoust
*/

#include "inc/n4s.h"

int     put_err(char* str)
{
  write(2, str, my_strlen(str));
  return (84);
}

void    my_putchar(char c, int fd)
{
  write(fd, &c, 1);
}

void    my_putnbr(int nbr, int fd)
{
  if (nbr < 0)
    {
      my_putchar('-', fd);
      if (nbr < -9)
        my_putnbr((nbr / 10 * -1), fd);
      my_putchar((nbr % 10 * -1) + 48, fd);
    }
  else
    {
      if (nbr > 9)
        my_putnbr(nbr / 10, fd);
      my_putchar((nbr % 10) + 48, fd);
    }
}
