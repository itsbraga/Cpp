/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:57:39 by panther           #+#    #+#             */
/*   Updated: 2025/06/15 14:01:21 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

/******************************************************************************\
 * LIBRARIES
\******************************************************************************/

# include <iostream>
# include "../colors.hpp"
# include "Data.hpp"

/******************************************************************************\
 * DEFINES
\******************************************************************************/

# define SUCCESS 0
# define FAILURE 1

typedef unsigned long uintptr_t;

/******************************************************************************\
 * CLASS
\******************************************************************************/

class Serializer
{
	private:
			Serializer();
			Serializer(const Serializer& toCopy);
			Serializer&	operator=(const Serializer& toCopy);
			~Serializer();

	public:
			static uintptr_t	serialize(Data* ptr);
			static Data*		deserialize(uintptr_t raw);
};

#endif