/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:06:52 by annabrag          #+#    #+#             */
/*   Updated: 2025/01/05 20:33:52 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

void	capitalizeStr(std::string str)
{
	size_t	i;

	for (i = 0 ; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
	std::cout << str << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	for (int i = 1; i < argc; i++)
		capitalizeStr(argv[i]);
}
