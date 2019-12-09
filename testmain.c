/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezzahir <hamza.ezzahiry@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:14:39 by hezzahir          #+#    #+#             */
/*   Updated: 2019/12/09 21:08:25 by hezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int   main(int ac, char **av)
{
  char  *line;
  int   fd1;
  int   fd2;

  fd1 = open(av[1], O_RDONLY);
  fd2 = open(av[2], O_RDONLY);
  while (get_next_line(fd1, &line))
  {
      printf("%s\n",line);
      free(line);
  }
  printf("\n==================================\n");
  while (get_next_line(fd2, &line))
  {
      printf("%s\n",line);
      free(line);
  }
  return (0);
}

