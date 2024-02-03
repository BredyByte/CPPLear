#include "main.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string GetData(std::string message ,int type) {
	std::string data;

	std::cout << message;
	std::getline(std::cin, data);

	if (std::cin.eof()) {
		std::exit(1);
	}

	if (type == 1 && data.length() != 0 && std::isdigit(data[0])) {
		return (data);
	}
	else if (type == 0 && data.length() != 0 && std::isalnum(data[0])) {
		return (data);
	}
	else {
		return (GetData(message, type));
	}
}

int main() {
	PhoneBook book;

	while (1) {
		std::string command = GetData("> ", 0);

		if (command == "EXIT") {
			break;
		}
		else if (command == "ADD") {
			book.Add();
		}
		else if (command == "SEARCH") {
			book.Search();
		}
		else {
			std::cout << "Invalid command: [SEARCH, ADD, EXIT]" << std::endl;
		}
	}
	return (0);
}
