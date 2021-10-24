/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanusong <hanusong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 23:16:43 by hanusong          #+#    #+#             */
/*   Updated: 2021/10/25 00:20:45 by hanusong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_prime(int nb)
{
	int	num;

	num = 3;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb == 3)
		return (1);
	if (nb % 2 == 0)
		return (0);
	if (nb == 2147483647)
		return (nb);
	while (num < 46341 && num * num <= nb)
	{
		if (nb % num == 0)
			return (0);
		num += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (nb == 2147483647)
		return (nb);
	while (nb < 2147483647 && ft_find_prime(nb) != 1)
		nb++;
	return (nb);
}
