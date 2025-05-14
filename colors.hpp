/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:00:51 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/13 21:19:53 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
# define COLORS_HPP

/******************************************************************************\
 * COLORS
\******************************************************************************/

# define RESET  		"\e[0m"

# define BOLD			"\e[1m"
# define ITAL			"\e[3m"
# define UNDERLINE		"\e[4m"

# define BLACK			"\e[30m"
# define GRAY			"\e[90m"
# define RED			"\e[31m"
# define GREEN			"\e[32m"
# define YELLOW			"\e[33m"
# define ORANGE			"\e[38;5;208m"
# define BLUE			"\e[34m"
# define PURPLE			"\e[35m"
# define HOT_PINK		"\e[38;2;255;105;180m"
# define PINK			"\e[38;2;255;182;193m"
# define CYAN			"\e[36m"
# define WHITE			"\e[37m"

# define LIGHT_GRAY		"\e[38;2;173;165;165m"
# define LIGHT_GRAY2	"\e[38;2;211;211;211m"

// Pastel colors
# define PG				"\e[38;2;173;235;179m" // green
# define PGG			"\e[38;2;152;168;105m" // green
# define PB				"\e[38;2;179;235;242m" // blue
# define PY				"\e[38;2;255;234;150m" // yellow
# define PP				"\e[38;2;211;211;255m" // purple
# define PO				"\e[38;2;255;178;127m" // orange

#endif