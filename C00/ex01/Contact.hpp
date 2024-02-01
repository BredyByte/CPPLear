#ifndef CONTACT_HPP
#define CONTACT_HPP
#include "main.hpp"

class Contact {
public:
	// Constructor
	Contact();

	// Destructor
	~Contact();

	// Setters
	void SetFirst(std::string data);
	void SetLast(std::string data);
	void SetNick(std::string data);
	void SetPhone(std::string data);
	void SetSecret(std::string data);

	// Getters
	std::string GetFirst(void);
	std::string GetLast(void);
	std::string GetNick(void);
	std::string GetPhone(void);
	std::string GetSecret(void);

private:
	// Attributes
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif
