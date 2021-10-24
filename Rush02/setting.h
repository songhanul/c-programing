#ifndef SETTING_H
# define SETTING_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_dictionary{
	char	num[100];
	char	name[20];
	int		len;
}			t_dict;

char	*open_read_file(char *f_name);
int		buffer_line_count(char *buffer);
t_dict	*mk_struct_pointer(int cnt);
t_dict	*input_buffer_struct(t_dict *dict, char *buffer, int flag);
t_dict	*struct_length_input(t_dict *dict, int cnt);
t_dict	*read_dictionary(char *file_name);
void	putstr(char *str);

#endif
