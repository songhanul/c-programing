#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include "setting.h"

/*
read file function
input : file name
output : buffer
*/
char	*open_read_file(char *f_name)
{
	int		fd;
	char	*buffer;
	char	array[10000];

	buffer = &array[0];
	fd = open(f_name, O_RDONLY);
	if (fd == -1)
		putstr("Dict Error\n");
	read(fd, array, 10000);
	if (close(fd) == -1)
		putstr("Dict Error\n");
	return (buffer);
}

/* buffer line count field = ':' */
int	buffer_line_count(char *buffer)
{
	int	cnt;

	cnt = 0;
	while (*buffer)
	{
		if (*buffer == ':')
			cnt++;
		buffer++;
	}
	return (cnt);
}

/*(buffer > struct) in order to make struct pointer
 * input : buffer
 * output: struct(name, num, len) */
t_dict	*mk_struct_pointer(int cnt)
{
	t_dict	*dict;

	dict = malloc(sizeof(struct s_dictionary) * cnt);
	return (dict);
}

/*buffer >> struct
 * input : struct, buffer, flag(0 or 1)
 * output: struct (name(ok), num(ok), len(more)*/
t_dict	*input_buffer_struct(t_dict *dict, char *buffer, int flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*buffer != '\n' && *buffer != '\0')
	{
		if (*buffer == ':')
			flag = 1;
		else if (flag == 0)
		{
			if (*buffer >= '0' && *buffer <= '9')
				dict[0].num[i++] = *buffer;
		}
		else if (flag == 1)
			if (*buffer >= 33 && *buffer <= 126)
				dict[0].name[j++] = *buffer;
		buffer++;
	}
	if (*buffer != '\0')
		input_buffer_struct(dict + 1, buffer + 1, 0);
	return (dict);
}

/*struct number length input*/
t_dict	*struct_length_input(t_dict *dict, int cnt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < cnt)
	{
		while (dict[0].num[i])
		{
			i++;
		}
		dict[0].len = i;
		i = 0;
		dict = dict + 1;
		j++;
	}
	dict = dict - cnt;
	return (dict);
}
