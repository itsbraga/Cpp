/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:21:52 by art3mis           #+#    #+#             */
/*   Updated: 2025/06/06 18:42:14 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main( void )
{
	std::cout << BOLD "________________ MAIN FROM PROJECT ________________\n" << RESET << std::endl;

	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap( c, d );
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << BOLD "\n\n\n_____________________ MY MAIN ______________________\n" << RESET << std::endl;

	std::cout << BOLD "\n======[ Swap tests ]======\n" RESET << std::endl;

	int e = 9;
	int f = 6;

	std::cout << BOLD PP "[Before swap]\t" RESET "e: " PY << e << RESET ", f: " PY << f
			  << RESET << std::endl;
	::swap( e, f );
	std::cout << BOLD PINK "[After swap]\t" RESET "e: " PO << e << RESET ", f: " PO << f
			  << RESET << std::endl;

	char g = 'G';
	char h = 'H';

	std::cout << std::endl;
	std::cout << BOLD PP "[Before swap]\t" RESET "g: " PY << g << RESET ", h: " PY << h
			  << RESET << std::endl;
	::swap( g, h );
	std::cout << BOLD PINK "[After swap]\t" RESET "g: " PO << g << RESET ", h: " PO << h
			  << RESET << std::endl;

	std::string test = "test";
	std::string test2 = "Hello World";

	std::cout << std::endl;
	std::cout << BOLD PP "[Before swap]\t" RESET "test: " PY << test << RESET ", test2: " PY << test2
			  << RESET << std::endl;
	::swap( test, test2 );
	std::cout << BOLD PINK "[After swap]\t" RESET "test: " PO << test << RESET ", test2: " PO << test2
			  << RESET << std::endl;

	std::cout << BOLD "\n=====[ Min/Max tests ]=====\n" RESET << std::endl;

	int i = 42;
	int j = 69;

	std::cout << "min( i, j ) = " BOLD HOT_PINK << ::min<int>( i, j ) << RESET << std::endl;
	std::cout << "max( i, j ) = " BOLD PINK << ::max<int>( i, j ) << RESET << std::endl;

	long long k = -9223372036854775;
	long long l = -9223372036854800;

	std::cout << "min( k, l ) = " BOLD BLUE << ::min<long long>( k, l ) << RESET << std::endl;
	std::cout << "max( k, l ) = " BOLD PB << ::max<long long>( k, l ) << RESET << std::endl;

	unsigned char m = 'm';
	unsigned char n = 'N'; // higher in ASCII table

	std::cout << "min( m, n ) = " BOLD PGG << ::min<unsigned char>( m, n ) << RESET << std::endl;
	std::cout << "max( m, n ) = " BOLD PG << ::max<unsigned char>( m, n ) << RESET << std::endl;
	std::cout << std::endl;
	return (SUCCESS);
}
