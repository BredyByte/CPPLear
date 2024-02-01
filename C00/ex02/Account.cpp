#include "Account.hpp"

/*
	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;
*/

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << initial_deposit << ";" << "created" << std::endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";" << "closed" << std::endl;
}


/* bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const; */

bool	makeWithdrawal( int withdrawal ) {
 std::cout << "withdrawal" << std::endl;
}

void Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	std::cout << "amount:" << _amount << ";";
	this->_nbDeposits++;
	std::cout << "nd_deposits:" << this->_nbDeposits << std::endl;
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << ";" << std::endl;
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void ) {
	std::time_t	t = std::time(NULL);
	std::tm		*tm = std::localtime(&t);

	std::cout << "[";
	std::cout << tm->tm_year + 1900;
	std::cout << ((tm->tm_mon + 1) < 10 ? "0" : "") << (tm->tm_mon + 1);
	std::cout << ((tm->tm_mday) < 10 ? "0" : "") << (tm->tm_mday);
	std::cout << "_";
	std::cout << (tm->tm_hour < 10 ? "0" : "") << tm->tm_hour;
	std::cout << (tm->tm_min < 10 ? "0" : "") << tm->tm_min;
	std::cout << (tm->tm_sec < 10 ? "0" : "") << tm->tm_sec;
	std::cout << "] ";
}
