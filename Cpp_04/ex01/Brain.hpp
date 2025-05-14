/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 05:05:35 by panther           #+#    #+#             */
/*   Updated: 2025/05/14 00:53:49 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include "../../colors.hpp"

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

		void				setIdea(unsigned int i, std::string idea);
		const std::string&	getIdea(unsigned int i) const;
};

#endif