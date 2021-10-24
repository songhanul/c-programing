#include<unistd.h>

void	putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
