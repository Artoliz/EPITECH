/*
** my_framebuffer_create.c for my_framebuffer_create in /home/descou_c/Graphic/wireframe
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Mon Dec  5 09:26:25 2016 Charles Descoust
** Last update Tue Dec 13 09:38:06 2016 Charles Descoust
*/

#include "inc/my.h"

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  int                   i;
  sfUint8               *pixels;
  t_my_framebuffer      *buffer;

  pixels = malloc(width * height * 4 * sizeof(*pixels));
  if (pixels == NULL)
    exit(84);
  i = 0;
  while (i < width * height * 4)
    {
      pixels[i] = 0;
      i = i + 1;
    }
  buffer = malloc(sizeof(t_my_framebuffer));
  buffer->pixels = pixels;
  buffer->width = width;
  buffer->height = height;
  return (buffer);
}
