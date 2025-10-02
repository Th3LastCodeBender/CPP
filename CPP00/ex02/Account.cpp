/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:11:47 by lparolis          #+#    #+#             */
/*   Updated: 2025/09/24 16:50:49 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <cstdio>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit)
{
	this->_displayTimestamp();
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	
	_totalAmount += initial_deposit; 
	
	std::cout << "index:" << this->_accountIndex << \
				 ";amount:" << this->_amount << \
				 ";created" << \
				std::endl;
}

Account::~Account()
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
				 ";amount:" << this->_amount << \
				 ";closed" << \
				std::endl;
}

void	Account::_displayTimestamp( void )
{
    time_t rawtime;
    struct tm* timeinfo;
    char buffer[20];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    std::sprintf(buffer, "[%04d%02d%02d_%02d%02d%02d]",
                 timeinfo->tm_year + 1900,
                 timeinfo->tm_mon + 1,
                 timeinfo->tm_mday,
                 timeinfo->tm_hour,
                 timeinfo->tm_min,
                 timeinfo->tm_sec);

    std::cout << buffer << " ";
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << \
				 ";total:" << _totalAmount << \
				 ";deposits:" << _totalNbDeposits << \
				 ";withdrawals:" <<	_totalNbWithdrawals 
				<< std::endl;
}

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	
	std::cout << "index:" << _accountIndex << \
				 ";amount:" << _amount << \
				 ";deposits:" << _nbDeposits << \
				 ";withdrawals:" << _nbWithdrawals << \
				std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_displayTimestamp();

	_nbDeposits++;
	_totalNbDeposits++;
	
	std::cout << "index:" << _accountIndex << \
				 ";p_amount:" << _amount << \
				 ";deposit:" << deposit;

	_amount += deposit;
	_totalAmount += deposit;
	
	std::cout << ";amount:" << _amount << \
				 ";nb_deposits:" << _nbDeposits << \
				std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();

	std::cout << "index:" << _accountIndex << \
				 ";p_amount:" << _amount << \
				 ";withdrawal:";

	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (true);
	} 
	else
	{
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		std::cout << withdrawal;
	}

	_amount -= withdrawal;
	_totalAmount -=withdrawal;

	std::cout << ";amount:" << _amount << \
				 ";nb_withdrawals:" << _nbWithdrawals << \
				std::endl;
	return (true);
}

int	Account::checkAmount( void ) const
{
	return (0);
}

int	Account::getNbAccounts( void )
{
	return(_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}