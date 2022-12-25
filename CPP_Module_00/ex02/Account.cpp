/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:40:20 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/25 05:06:17 by yhwang           ###   ########.fr       */
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
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ';'
		<< "total:" << Account::getTotalAmount() << ';'
		<< "deposits:" << Account::getNbDeposits() << ';'
		<< "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
:_accountIndex(_nbAccounts++),_amount(initial_deposit),_nbDeposits(0),_nbWithdrawals(0)
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ';'
		<< "amount:" << initial_deposit << ';'
		<< "created" << std::endl;
	Account::_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ';'
		<< "amount:" << checkAmount() << ';'
		<< "closed" << std::endl;
}

/* Account::makeDeposit
	ex	[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
*/
void	Account::makeDeposit(int deposit)
{
	int	p_amount;
	
	p_amount = Account::checkAmount();
	Account::_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ';'
		<< "p_amount:" << p_amount << ';'
		<< "deposit:" << deposit << ';'
		<< "amount:" << checkAmount() << ';'
		<< "nb_deposits:" << Account::_nbDeposits << std::endl;
}

/* Account::makeWithdrawal
	ex_ref.	[19920104_091532] index:0;p_amount:47;withdrawal:refused
	ex_app.	[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
*/
bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;

	p_amount = checkAmount();
	//refuse
	if (p_amount - withdrawal < 0)
	{
		_displayTimestamp();
		std::cout << "index:" << Account::_accountIndex << ';'
			<< "p_amount:" << p_amount << ';'
			<< "withdrawal:" << "refused" << std::endl;
		return (false);
	}
	//approve
	else
	{
		Account::_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		Account::_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_displayTimestamp();
		std::cout << "index:" << Account::_accountIndex << ';'
			<< "p_amount:" << p_amount << ';'
			<< "withdrawal:" << withdrawal << ';'
			<< "amount:" << checkAmount() << ';'
			<< "nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
		return (true);
	}
}

int	Account::checkAmount(void) const
{
	return (Account::_amount);
}

/* Account::displayStatus
	ex	[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
*/
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ';'
		<< "amount:" << checkAmount() << ';'
		<< "deposits:" << Account::_nbDeposits << ';'
		<< "withdrawals:" <<Account:: _nbWithdrawals << std::endl;
}

/* Account::_displayTimestamp
	ex	[19920104_091532]: [YYYYMMDD_HHMMSS]
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

Account::Account()
{
	std::cout << "This is for private. "
		<< "So it won't appear in terminal" << std::endl;
}
