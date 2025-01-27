/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:37:52 by art3mis           #+#    #+#             */
/*   Updated: 2025/01/27 21:41:34 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>		// std::cout
#include <iomanip>		// std::put_time
#include <ctime>		// std::time_t, struct std::tm, std::localtime

Account::Account(int initial_deposit)
{
	(void)initial_deposit;
	// std::cout << "Account: Constructor called :)" << std::endl;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::~Account(void)
{
	// std::cout << "Account: Destructor called :(" << std::endl;
}


int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	_displayTimestamp(void)
{
	std::time_t	currentTime = std::time(NULL);
	std::tm		*localTime = std::localtime(&currentTime);

	std::cout << "["
			  << (localTime->tm_year + 1900) << "-" << std::setfill('0')
			  << std::setw(2) << (localTime->tm_mon + 1) << "-"
			  << std::setw(2) << localTime->tm_mday << " "
			  << std::setw(2) << localTime->tm_hour << ":"
			  << std::setw(2) << localTime->tm_min << ":"
			  << std::setw(2) << localTime->tm_sec
			  << "] ";
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts: " << getNbAccounts() << std::endl;
	std::cout << "total: " << getTotalAmount() << std::endl;
	std::cout << "deposits: " << getNbDeposits() << std::endl;
	std::cout << "withdrawals: " << getNbWithdrawals() << std::endl;
}

// void	Account::displayStatus(void) const
// {
	
// }

// int	Account::checkAmount(void) const
// {
	
// }

// void	Account::makeDeposit(int deposit)
// {
	
// }

// bool	Account::makeWithdrawal(int withdrawal)
// {
	
// }
