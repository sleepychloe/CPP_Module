/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:40:20 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/24 23:15:11 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

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

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ';'
		<< "total:" << Account::getTotalAmount() << ';'
		<< "deposits:" << Account::getNbDeposits() << ';'
		<< "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
:_accountIndex(_nbAccounts++),_amount(initial_deposit),_nbDeposits(0),_nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';' << "amount:" << initial_deposit << ';'
	<< "created" << std::endl;
	_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	
}
/*
void	Account::makeDeposit(int deposit)
{

}

bool	Account::makeWithdrawal(int withdrawal)
{

}

int	Account::checkAmount(void) const
{

}

void	Account::displayStatus(void) const
{

}
*/
void	Account::_displayTimestamp(void)
{
	std::time_t	now = std::time(0);
	std::tm		*ltm = std::localtime(&now);
	int		year = 1900 + ltm->tm_year;
	int		month = 1 + ltm->tm_mon;
	int		day = ltm->tm_mday;
	int		hour = ltm->tm_hour;
	int		min = ltm->tm_min;
	int		sec = ltm->tm_sec;

	std::cout << '[' << year << std::setfill('0') << std::setw(2) << month
		<< std::setfill('0') << std::setw(2) << day << '_'
		<< std::setfill('0') << std::setw(2) << hour
		<< std::setfill('0') << std::setw(2) << min
		<< std::setfill('0') << std::setw(2) << sec << "] ";
}
