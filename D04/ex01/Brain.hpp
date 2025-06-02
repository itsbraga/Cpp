/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 05:05:35 by panther           #+#    #+#             */
/*   Updated: 2025/05/24 17:54:17 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

typedef unsigned int uint32_t;

# include <iostream>
# include "../colors.hpp"

# define SUCCESS 0
# define FAILURE 1

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Brain
{
	public:
			Brain();
			Brain(const Brain& toCopy);
			Brain&	operator=(const Brain& toCopy);
			virtual ~Brain();

			std::string		ideas[100];

			void				setIdea(uint32_t i, std::string idea);
			const std::string&	getIdea(uint32_t i) const;
};

#endif