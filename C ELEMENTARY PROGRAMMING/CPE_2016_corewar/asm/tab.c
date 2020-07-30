/*
** tab.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/ASM/asm
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Thu Mar 16 11:31:23 2017 Charles Aubert
** Last update Sun Apr  2 15:41:09 2017 Charles Descoust
*/

#include "./include/my.h"
#include "./include/asm.h"

check	*create_tab()
{
  check *tab;

  if ((tab = malloc(sizeof(check) * 19)) == NULL)
    return (NULL);
  tab[0] = check_line_zjmp;
  tab[1] = check_line_ld;
  tab[2] = check_line_st;
  tab[3] = check_line_fork;
  tab[4] = check_line_live;
  tab[5] = check_line_or;
  tab[6] = check_line_xor;
  tab[7] = check_line_add;
  tab[8] = check_line_ldi;
  tab[9] = check_line_sti;
  tab[10] = check_line_and;
  tab[11] = check_line_lld;
  tab[12] = check_line_lldi;
  tab[13] = check_line_lfork;
  tab[14] = check_line_aff;
  tab[15] = check_line_sub;
  tab[16] = check_label_creation;
  tab[17] = check_line_ignore;
  tab[18] = NULL;
  return (tab);
}

t_ptr	*get_tabptr_cor()
{
  t_ptr *my_tab;

  if ((my_tab = malloc(sizeof(*my_tab) * 16)) == NULL)
    return (NULL);
  my_tab[0].fct = check_type_LIVE;
  my_tab[0].flag = MY_LIVE;
  my_tab[1].fct = check_type_LD;
  my_tab[1].flag = MY_LD;
  my_tab[2].fct = check_type_ST;
  my_tab[2].flag = MY_ST;
  my_tab[3].fct = check_type_ADD;
  my_tab[3].flag = MY_ADD;
  my_tab[4].fct = check_type_SUBB;
  my_tab[4].flag = MY_SUB;
  my_tab[5].fct = check_type_AND;
  my_tab[5].flag = MY_AND;
  my_tab[6].fct = check_type_OR;
  my_tab[6].flag = MY_OR;
  my_tab[7].fct = check_type_XOR;
  my_tab[7].flag = MY_XOR;
  my_tab = get_tabptr_end(my_tab);
  return (my_tab);
}

t_ptr	*get_tabptr_end(t_ptr *my_tab)
{
  my_tab[8].fct = check_type_ZJMP;
  my_tab[8].flag = MY_ZJMP;
  my_tab[9].fct = check_type_LDI;
  my_tab[9].flag = MY_LDI;
  my_tab[10].fct = check_type_STI;
  my_tab[10].flag = MY_STI;
  my_tab[11].fct = check_type_FORK;
  my_tab[11].flag = MY_FORK;
  my_tab[12].fct = check_type_LLD;
  my_tab[12].flag = MY_LLD;
  my_tab[13].fct = check_type_LLDI;
  my_tab[13].flag = MY_LLDI;
  my_tab[14].fct = check_type_LFORK;
  my_tab[14].flag = MY_LFORK;
  my_tab[15].fct = check_type_AFF;
  my_tab[15].flag = MY_AFF;
  return (my_tab);
}
