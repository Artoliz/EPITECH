/*
** my_memcpy.c for utils in /home/pierre/epitech/lib/my/src/utils
**
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
**
** Started on  Mon Apr 10 10:15:00 2017 Pierre J. Alderman
** Last update Sat Apr 15 17:17:14 2017 Charles Aubert
*/

#include <stdlib.h>

/*
** my_memcpy copies what is pointed by the address  src into dest.
** its stops when the first NULL byte is encountered.
** Use my_memncpy to copy n bytes.
*/
void		*my_memcpy(void *dest, void *src)
{
  char		*tmp_dest;
  char		*tmp_src;
  size_t	i;

  tmp_src = (char *)src;
  tmp_dest = (char *)dest;
  i = 0;
  while (tmp_src[i])
    {
      tmp_dest[i] = tmp_src[i];
      ++i;
    }
  return ((void *)tmp_dest);
}

/*
** my_menmcpy copies n bytes pointed by src into dest.
** Unlike my_memcpy, it also copies NULL bytes.
*/
void		*my_memncpy(void *dest, void *src, size_t n)
{
  char		*tmp_dest;
  char		*tmp_src;
  size_t	i;

  tmp_src = (char *)src;
  tmp_dest = (char *)dest;
  i = 0;
  while (i < n)
    {
      tmp_dest[i] = tmp_src[i];
      ++i;
    }
  return ((void *)tmp_dest);
}
