/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 02:40:05 by panther           #+#    #+#             */
/*   Updated: 2025/05/21 17:38:47 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <string>
# include <cstdlib>
# include <iostream>
# include <fstream>
# include "../colors.hpp"

# define SUCCESS 0
# define FAILURE 1

/******************************************************************************\
 * FUNCTIONS
\******************************************************************************/

void	openAndReplace(const std::string& content, const std::string& s1,
						const std::string& s2);

#endif