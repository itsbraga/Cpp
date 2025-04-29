/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:37:52 by annabrag          #+#    #+#             */
/*   Updated: 2025/04/28 23:26:17 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "../../colors.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>	// std::time_t, struct std::tm, std::localtime

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << BOLD PB << _accountIndex << RESET ";"
			  << "amount:" << BOLD PB << initial_deposit << RESET ";"
			  << BOLD PG "created" RESET
			  << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << BOLD PB << _accountIndex << RESET ";"
			  << "amount:" << BOLD PB << _amount << RESET ";"
			  << BOLD PO "closed" RESET
			  << std::endl;
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp()
{
	std::time_t	currentTime = std::time(0);
	std::tm		*localTime = std::localtime(&currentTime);
	char		buffer[17];

	std::strftime(buffer, 17, "%Y%m%d_%H%M%S", localTime);
	std::cout << "[" << buffer << "] ";
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << BOLD PB << getNbAccounts() << RESET ";"
			  << "total:" << BOLD PB << getTotalAmount() << RESET ";"
			  << "deposits:" << BOLD PB << getNbDeposits() << RESET ";"
			  << "withdrawals:" << BOLD PB << getNbWithdrawals() << RESET
			  << std::endl;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << BOLD PB << _accountIndex << RESET ";"
			  << "amount:" << BOLD PB << _amount << RESET ";"
			  << "deposits:" << BOLD PB << _nbDeposits << RESET ";"
			  << "withdrawals:" << BOLD PB << _nbWithdrawals << RESET
			  << std::endl;
}

int	Account::checkAmount() const
{
	return (_amount);
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << BOLD PB << _accountIndex << RESET ";"
			  << "p_amount:" << BOLD PB << _amount << RESET ";"
			  << "deposit:" << BOLD PB << deposit << RESET ";";
	
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << "amount:" << BOLD PB << _amount << RESET ";"
			  << "nb_deposits:" << BOLD PB << _nbDeposits << RESET
			  << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << BOLD PB << _accountIndex << RESET ";"
			  << "p_amount:" << BOLD PB << _amount << RESET ";"
			  << "withdrawal:";

	if (_amount >= withdrawal)
	{
		std::cout << BOLD PB << withdrawal << RESET ";";
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;

		std::cout << "amount:" << BOLD PB << _amount << RESET ";"
				  << "nb_withdrawals:" << BOLD PB << _nbWithdrawals << RESET
				  << std::endl;
		return (true);
	}
	else
	{
		std::cout << BOLD RED "refused" RESET << std::endl;
		return (false);
	}
}
