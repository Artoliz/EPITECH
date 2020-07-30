/*
** get_tab_obj.c for  in /home/miklox/semestre2/infographie/rt1test
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Thu May 25 15:41:48 2017 Bastien LECUSSAN
** Last update Sun May 28 18:56:32 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

t_normal_vtx	*get_tab_normal_vtx(t_normal_vtx *tmp_n, t_obj *obj,
				    int count)
{
  t_normal_vtx	*n;
  t_normal_vtx	*save;

  while (tmp_n != NULL)
    {
      count += 1;
      tmp_n = tmp_n->prev;
    }
  tmp_n = obj->normal;
  if ((n = malloc(sizeof(*n) * (count + 1))) == NULL)
    return (NULL);
  obj->normal_nb = count;
  count = 0;
  while (tmp_n != NULL)
    {
      n[count].normal.x = tmp_n->normal.x;
      n[count].normal.y = tmp_n->normal.y;
      n[count].normal.z = tmp_n->normal.z;
      save = tmp_n;
      tmp_n = tmp_n->prev;
      free(save);
      count += 1;
    }
  return (n);
}

t_texture_vtx	*get_tab_texture_vtx(t_texture_vtx *tmp_vt, t_obj *obj,
				     int count)
{
  t_texture_vtx	*txt;
  t_texture_vtx	*save;

  while (tmp_vt != NULL)
    {
      count += 1;
      tmp_vt = tmp_vt->prev;
    }
  tmp_vt = obj->texture;
  if ((txt = malloc(sizeof(*txt) * (count + 1))) == NULL)
    return (NULL);
  obj->texture_nb = count;
  count = 0;
  while (tmp_vt != NULL)
    {
      txt[count].texture.x = tmp_vt->texture.x;
      txt[count].texture.y = tmp_vt->texture.y;
      save = tmp_vt;
      tmp_vt = tmp_vt->prev;
      free(save);
      count += 1;
    }
  return (txt);
}

t_pos_vtx	*get_tab_pos_vtx(t_pos_vtx *tmp_p, t_obj *obj,
				 int count, sfVector3f rotate)
{
  t_pos_vtx	*pos;
  t_pos_vtx	*save;

  while (tmp_p != NULL)
    {
      count += 1;
      tmp_p = tmp_p->prev;
    }
  tmp_p = obj->pos;
  if ((pos = malloc(sizeof(*pos) * (count + 1))) == NULL)
    return (NULL);
  obj->pos_nb = count;
  count = 0;
  while (tmp_p != NULL)
    {
      pos[count].pos.x = tmp_p->pos.x;
      pos[count].pos.y = tmp_p->pos.y;
      pos[count].pos.z = tmp_p->pos.z;
      rotate_xyz_obj(&pos[count].pos, &rotate);
      save = tmp_p;
      tmp_p = tmp_p->prev;
      free(save);
      count += 1;
    }
  return (pos);
}

t_obj		*get_tab_obj(t_obj *obj)
{
  t_pos_vtx	*tmp_p;
  t_texture_vtx	*tmp_v;
  t_normal_vtx	*tmp_n;
  sfVector3f	rotate;

  rotate.x = ROTATION_OBJ_X;
  rotate.y = ROTATION_OBJ_Y;
  rotate.z = ROTATION_OBJ_Z;
  tmp_p = obj->pos;
  tmp_v = obj->texture;
  tmp_n = obj->normal;
  if ((obj->pos = get_tab_pos_vtx(tmp_p, obj, 0, rotate)) == NULL)
    return (NULL);
  if (tmp_v == NULL)
    obj->texture = NULL;
  else if ((obj->texture = get_tab_texture_vtx(tmp_v, obj, 0)) == NULL)
    return (NULL);
  if (tmp_n == NULL)
    obj->normal = NULL;
  else if ((obj->normal = get_tab_normal_vtx(tmp_n, obj, 0)) == NULL)
    return (NULL);
  return (obj);
}
