/*
** get_next_line.h for  in /home/BLENEA_T/Projects/CPE/CPE_2016_getnextline/test
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Tue Jan 10 16:33:07 2017 Thomas BLENEAU
** Last update Fri Jan 13 18:07:55 2017 Thomas BLENEAU
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef READ_SIZE
#  define READ_SIZE (4096)
# endif /* !READ_SIZE */

/*
** Include de la LibC
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

/*
** Déclaration de la Strucutre GetNextLine
*/

typedef struct	s_get_line
{
  char		*str;
  char		*file;
  int		i;
  int		reader;
}		t_get_line;

/*
** Déclaration de la Strucutre pour read
*/

typedef struct	s_read
{
  int		var;
  int		boolean;
  int		reader;
}		t_read;

/*
** Prototypes de fonctions
*/

char		*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H */
