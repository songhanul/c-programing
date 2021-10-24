#ifndef CHECKER_H
# define CHECKER_H

# include "setting.h"

int	length_count(char *argv);
int	dict_line_count(t_dict *dict);
void	curser(char *argv, t_dict *dict, int n, int i);
void	checker1(char nbr, int i, t_dict *dict);
void	checker2(char nbr, int i, t_dict *dict);

#endif
