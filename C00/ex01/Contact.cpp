#include "Contact.hpp"

Contact::Contact() {
	std::cout << "Constructor called" << std::endl;
}

Contact::~Contact() {
	std::cout << "Destrutcor called" << std::endl;
}

// Setters
void Contact::SetFirstN(std::string data) {
	_firstName = data;
}
void Contact::SetLastN(std::string data) {
	_lastName = data;
}
void Contact::SetNickN(std::string data) {
	_nickName = data;
}
void Contact::SetPhoneN(std::string data) {
	_phoneNumber = data;
}
void Contact::SetSecret(std::string data) {
	_darkestSecret = data;
}

// Getters
std::string Contact::GetFirstN(void) {
	return (_firstName);
}
std::string Contact::GetLastN(void) {
	return (_lastName);
}
std::string Contact::GetNickN(void) {
	return (_nickName);
}
std::string Contact::GetPhoneN(void) {
	return (_phoneNumber);
}
std::string Contact::GetSecret(void) {
	return (_darkestSecret);
}
