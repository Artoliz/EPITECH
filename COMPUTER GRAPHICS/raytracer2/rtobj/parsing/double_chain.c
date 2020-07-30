/*
** double_chain.c for  in /home/miklox/semestre2/infographie/rt1test/parsing
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Wed May 24 13:09:55 2017 Bastien LECUSSAN
** Last update Wed May 24 13:18:17 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

t_face_vtx      *double_chain_face_vtx(t_face_vtx *pos)
{
  t_face_vtx    *tmp;

  tmp = NULL;
  while (pos != NULL)
    {
      pos->prev = tmp;
      tmp = pos;
      pos = pos->next;
    }
  pos = tmp;
  return (pos);
}

t_texture_vtx   *double_chain_texture_vtx(t_texture_vtx *pos)
{
  t_texture_vtx *tmp;

  tmp = NULL;
  while (pos != NULL)
    {
      pos->prev = tmp;
      tmp = pos;
      pos = pos->next;
    }
  pos = tmp;
  return (pos);
}

t_pos_vtx       *double_chain_pos_vtx(t_pos_vtx *pos)
{
  t_pos_vtx     *tmp;

  tmp = NULL;
  while (pos != NULL)
    {
      pos->prev = tmp;
      tmp = pos;
      pos = pos->next;
    }
  pos = tmp;
  return (pos);
}

t_normal_vtx    *double_chain_normal_vtx(t_normal_vtx *pos)
{
  t_normal_vtx  *tmp;

  tmp = NULL;
  while (pos != NULL)
    {
      pos->prev = tmp;
      tmp = pos;
      pos = pos->next;
    }
  pos = tmp;
  return (pos);
}
