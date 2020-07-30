/*
** my_square_root.c for  in /home/charliebegood/delivery/CPool_Day05
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Fri Oct  7 15:29:02 2016 Charles AUBERT
** Last update Tue Nov  8 09:18:02 2016 Charles AUBERT
*/

int	my_square_root(int nb)
{
  int	i;
  int	counter;

  i = 1;
  counter = 0;
  if (nb < 0)
    return (0);
  if (nb == 0)
    return (0);
  if (nb == 1)
    return (1);
  while (i <= nb)
    {
      counter = i * i;
      if (counter == nb)
	return (i);
      i += 1;
    }
  return (0);
}
