/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 00:36:49 by fedmarti          #+#    #+#             */
/*   Updated: 2016/01/02 03:06:39 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() \
	<< ";total:" << Account::getTotalAmount() \
	<< ";deposits:" << Account::getNbDeposits() \
	<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp( void )
{
	//need to figure out how to get time lul
	time_t	t = time(NULL);
	struct tm *tim = localtime(&t);

	std::cout << "[";
	std::cout << tim->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << tim->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << tim->tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << tim->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << tim->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << tim->tm_sec;
	std::cout << "] ";
}

void	Account::makeDeposit( int deposit )
{
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	this->_amount += deposit;
	this->_nbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
	<< ";p_amount:" << this->_amount - deposit \
	<< ";deposit:" << deposit \
	<< ";amount:" << this->_amount \
	<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > this->checkAmount())
	{
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex \
		<< ";p_amount:" << this->_amount \
		<< ";withdrawal:refused\n";
		return (false);
	}

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
	";p_amount:" << this->_amount + withdrawal << \
	";withdrawal:" << withdrawal << \
	";amount:" << this->_amount << \
	";nb_withdrawals:"<<this->_nbWithdrawals<<std::endl;
	return (true);
}

int	Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
	<< ";amount:" << this->_amount \
	<< ";deposits:" << this->_nbDeposits \
	<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

Account::Account( int initial_deposit ) : _amount(initial_deposit)
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = Account::getNbAccounts();
	
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created\n";
}

Account::~Account( void )
{
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
	
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed\n";
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;