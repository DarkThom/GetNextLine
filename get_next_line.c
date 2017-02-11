/*
** get_next_line.c for  in /home/BLENEA_T/Projects/CPE/CPE_2016_getnextline
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Tue Jan 10 16:35:18 2017 Thomas BLENEAU
** Last update Fri Jan 13 18:06:25 2017 Thomas BLENEAU
*/

#include "get_next_line.h"

static char	*get_buffer_data(char *str, const char *buffer,
				 int count, int boolean)
{
  int		i;
  int		j;

  i = 0;
  if (boolean == 0)
    {
      while (str != NULL && str[i] != '\0')
	i = i + 1;
      j = 0;
      while (buffer[j] != '\0' && j < count)
	str[i++] = buffer[j++];
      str[i] = '\0';
      return (str);
    }
  while (buffer[i] != '\0' && i < count)
    {
      str[i] = buffer[i];
      i = i + 1;
    }
  str[i] = '\0';
  return (str);
}

static char	*get_buff_allocation(char *buffer, int size)
{
  char		*str;
  int		i;

  i = -1;
  while (buffer != NULL && buffer[++i] != '\0');
  if (buffer == NULL)
    {
      if ((str = malloc(sizeof(char) * size)) == NULL)
	return (NULL);
      if (size > 0)
	str[0] = '\0';
      return (str);
    }
  if ((str = malloc(sizeof(char) * (i + 1 + size))) == NULL)
    return (NULL);
  str = get_buffer_data(str, buffer, i, 1);
  free(buffer);
  return (str);
}

static char	*get_strdup(const char *buffer)
{
  int		i;
  char		*str;

  i = -1;
  while (buffer != NULL && buffer[++i] != '\0');
  if ((str = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = -1;
  while (buffer[++i] != '\0')
    str[i] = buffer[i];
  str[i] = '\0';
  return (str);
}

static char	*read_next_x_bytes(char *str, char *buffer,
				  const int fd, int i)
{
  t_read	line;

  line.boolean = 0;
  line.reader = READ_SIZE;
  while (line.boolean == 0)
    {
      i = 0;
      line.var = 0;
      while (buffer != NULL && buffer[line.var])
	if (buffer[line.var++] == '\n')
	  i = i + 1;
      if (i != 0)
	return (buffer);
      if ((line.var = read(fd, str, line.reader)) <= 0 || (str[line.var] = '\0')
	  || ((buffer = get_buff_allocation(buffer, line.reader + 1)) == NULL))
	{
	  if (buffer != NULL && buffer[0] != '\0')
	    return (buffer);
	  free(str);
	  free(buffer);
	  return (NULL);
	}
      buffer = get_buffer_data(buffer, str, line.reader, line.boolean);
    }
  return (buffer);
}

char		*get_next_line(const int fd)
{
  static char   *buffer;
  t_get_line    line;

  line.reader = READ_SIZE;
  line.file = NULL;
  if (line.reader <= 0)
    return (NULL);
  if (((line.str = malloc(sizeof(char) * (line.reader + 1))) == NULL)
      || ((buffer = read_next_x_bytes(line.str, buffer, fd, 0)) == NULL))
    return (NULL);
  free(line.str);
  line.i = 0;
  while (buffer[line.i] != '\0' && buffer[line.i] != '\n')
    line.i = line.i + 1;
  line.str = buffer;
  if ((line.file = get_buff_allocation(line.file, line.i + 2)) == NULL)
      return (NULL);
  if ((buffer = line.str[line.i] == '\0' ? get_strdup("\0")
       : get_strdup(line.str + line.i + 1)) == NULL)
    return (NULL);
  line.file = get_buffer_data(line.file, line.str, line.i + 1, 1);
  line.file[line.i] = '\0';
  free(line.str);
  return (line.file);
}
