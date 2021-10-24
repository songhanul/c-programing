#include "setting.h"
#include "checker.h"

/*input number length count*/
int	length_count(char *argv)
{
	int	cnt;

	cnt = 0;
	while (*(argv++))
		cnt++;
	return (cnt);
}

/*dict line count*/
int	dict_line_count(t_dict *dict)
{
	int	cnt;

	cnt = 0;
	while (dict[0].len)
	{
		cnt++;
		dict++;
	}
	return (cnt);
}

/* let's move from seat 1 to seat 10 
 * move vector << */
void	curser(char *argv, t_dict *dict, int n, int i)
{
	if (n == i)
	{
		while (dict[0].len < 2)
		{
			if(dict[0].num[0] == argv[n - i])
			putstr(dict[0].name);
			dict++;
		}
		return ;
	}
	else if (argv[n - i] >= '1' && argv[n - i] <= '9')
	{
		if (i > 1)
			checker1(argv[n - 1], i, dict);
		else
			checker2(argv[n - 1], i, dict);
		argv[n - 1] = '0';
		curser(argv, dict, n, i);
	}
	else if (argv[n - i] == '0')
	{
		i++;
		curser(argv, dict, n, i);
	}
	else
	{
		putstr("Dict Error\n");
		return ;
	}
}

/*if less than 3digits, call checker1*/
void checker1(char nbr, int i, t_dict *dict)
{
	int	n;
	int	j;

	j = 0;
	while (dict[j].len < 3)
	{
		j++;
	}
	n = dict_line_count(dict);
	while (j < n)
	{
		if (dict[0].len == i)
			putstr(dict[0].name);
		j++;
	}
}

/*if 3digits or more, call checker2*/
void checker2(char nbr, int i, t_dict *dict)
{
	int n;
	int	j;

	j = 0;
	while (dict[0].len < 2)
	{
		if(dict[0].num[0] == nbr)
			putstr(dict[0].name);
		dict++;
	}
	while (dict[0].len < 3)
	{
		if(dict[0].num[0] == nbr)
			putstr(dict[0].name);
		dict++;
	}
}
