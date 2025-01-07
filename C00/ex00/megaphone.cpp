/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:06:52 by annabrag          #+#    #+#             */
/*   Updated: 2025/01/07 19:39:06 by art3mis          ###   ########.fr       */
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
