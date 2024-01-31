#include "Contact.hpp"

/* Contact some;
	some.SetFirstN("Davyd");
	some.SetLastN("Shrediinger");
	some.SetNickN("PollaMan");
	some.SetPhoneN("12-98-09-1");
	some.SetSecret("I have polla 1cm");

	some.GetFirstN();
	some.GetLastN();
	some.GetNickN();
	some.GetPhoneN();
	some.GetSecret(); */

int main(void)
{
	std::cout << "Welcome to PhoneBookX80 🙌!!!" << std::endl;
	while (1) {
		std::string command;

		std::cout << "Please enter a command: ";

		std::getline(std::cin, command);

		if (command == "EXIT")
			break;
		else if (command == "ADD")
			PhoneBook.createContact();
		else
			std::cout << "Invalid command, try again!" << std::endl;
	}
	return (0);
}
