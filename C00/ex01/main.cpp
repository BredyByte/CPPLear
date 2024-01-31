#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook book;

	std::cout << "Welcome to PhoneBookX80 🙌!!!" << std::endl;

	while (1) {
		std::string command;

		std::cout << "Please enter a command: ";

		std::getline(std::cin, command);

		if (command == "exit" || std::cin.eof())
			break;
		else if (command == "add")
			book.Add();
		else if (command == "search")
			book.PrintPhoneBook();
		else
			std::cout << "Invalid command, [search, add, exit]" << std::endl;
	}
	return (0);
}
