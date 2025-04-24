/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openAndReplace.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:26:19 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/22 18:27:24 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

static std::string	__replace(const std::string& content, const std::string& s1,
								const std::string& s2)
{
	std::string	result;
	size_t		pos;
	size_t		match_pos;

	if (s1.empty() == true)
		return (content);
	pos = 0;
	match_pos = 0;
	while (true)
	{
		match_pos = content.find(s1, pos);
		if (match_pos == std::string::npos)
			break ;
		result += content.substr(pos, match_pos - pos);
		result += s2;
		pos = match_pos + s1.length();
	}
	result += content.substr(pos);
	return (result);
}

void	openAndReplace(const std::string& filename, const std::string& s1,
						const std::string& s2)
{
	std::ifstream	infile;
	std::string		replaced;
	std::string		line;
	std::string		content;
	std::ofstream	outfile;

	infile.open(filename.c_str());
	if (!infile)
	{
		std::cerr << "Error: Cannot open file '" << filename << "'\n";
		std::exit(FAILURE);
	}
	while (std::getline(infile, line))
	{
		content += line;
		if (!infile.eof())
			content += '\n';
	}
	infile.close();
	replaced = __replace(content, s1, s2);
	outfile.open((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "Error: Cannot create output file '" << filename
				  << ".replace'\n";
		std::exit(FAILURE);
	}
	outfile << replaced;
	outfile.close();
}
