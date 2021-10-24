#include "setting.h"
#include<stdio.h>
#include "checker.h"

int	main(void)
{
	t_dict *dict;
	int	max_idx;
	dict = read_dictionary("numbers.dict");

	printf("\n\n-----dict-----");
	printf("\nname : %s\nnumber : %s len : %d\n", dict[0].name, dict[0].num, dict[0].len);
	printf("\nname : %s\nnumber : %s len : %d\n", dict[1].name, dict[1].num, dict[1].len);
	printf("\nname : %s\nnumber : %s len : %d\n", dict[2].name, dict[2].num, dict[2].len);
	printf("\nname : %s\nnumber : %s len : %d\n", dict[3].name, dict[3].num, dict[3].len);
	printf("\nname : %s\nnumber : %s len : %d\n", dict[4].name, dict[4].num, dict[4].len);
	
	max_idx = length_count("1") -1;
	printf("max_idx = %d\n", max_idx);
	printf("dict_line_count = %d\n", dict_line_count(dict));
	curser("1", dict, max_idx, 0);
	return 0;
}
