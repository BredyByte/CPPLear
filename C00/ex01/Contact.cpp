#include "Contact.hpp"
#include "main.hpp"

Contact::Contact() {

}

Contact::~Contact() {

}

// Setters
void Contact::SetFirst(std::string data) {
	_firstName = data;
}
void Contact::SetLast(std::string data) {
	_lastName = data;
}
void Contact::SetNick(std::string data) {
	_nickName = data;
}
void Contact::SetPhone(std::string data) {
	_phoneNumber = data;
}
void Contact::SetSecret(std::string data) {
	_darkestSecret = data;
}

// Getters
std::string Contact::GetFirst(void) {
	return (_firstName);
}
std::string Contact::GetLast(void) {
	return (_lastName);
}
std::string Contact::GetNick(void) {
	return (_nickName);
}
std::string Contact::GetPhone(void) {
	return (_phoneNumber);
}
std::string Contact::GetSecret(void) {
	return (_darkestSecret);
}
