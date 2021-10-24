#include"setting.h"

/* dictrionary struct
 * name / number / length(number) */
t_dict	*read_dictionary(char *file_name)
{
	char	*buffer;
	int		cnt;
	t_dict	*dict;

	buffer = open_read_file(file_name);
	cnt = buffer_line_count(buffer);
	dict = mk_struct_pointer(cnt);
	dict = input_buffer_struct(dict, buffer, 0);
	dict = struct_length_input(dict, cnt);
	return (dict);
}
