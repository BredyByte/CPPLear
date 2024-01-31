#ifndef CONTACT_HPP
#define CONTACT_HPP
#include "iostream"

class Contact {
public:
	// Constructor
	Contact();

	// Destructor
	~Contact();

	// Setters
	void SetFirstN(std::string data);
	void SetLastN(std::string data);
	void SetNickN(std::string data);
	void SetPhoneN(std::string data);
	void SetSecret(std::string data);

	// Getters
	std::string GetFirstN(void);
	std::string GetLastN(void);
	std::string GetNickN(void);
	std::string GetPhoneN(void);
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
