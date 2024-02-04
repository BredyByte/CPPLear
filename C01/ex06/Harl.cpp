#include "Harl.hpp"

Harl::Harl() {

}

Harl::~Harl() {

}

int levelToInt(const std::string& str) {
	if (str == "DEBUT") {
		return (DEBUT);
	}
	else if (str == "INFO") {
		return (INFO);
	}
	else if (str == "WARNING") {
		return (WARNING);
	}
	else if (str == "ERROR") {
		return (ERROR);
	}
	else {
		return (-1);
	}
}

void Harl::complain(std::string level) {
	int levelInt = levelToInt(level);

	switch (levelInt) {
		case DEBUT:
			(this->*complain_ptr[DEBUT])();
		case INFO:
			(this->*complain_ptr[INFO])();
		case WARNING:
			(this->*complain_ptr[WARNING])();
		case ERROR:
			(this->*complain_ptr[ERROR])();
			break;
		default:
		    std::cerr << "Error: Unknown log level." << std::endl;
			break;
	}
}

void Harl::_debut() {
	std::cout << "[ DEBUT ]" << std::endl;
	std::cout << "<someDebutText>." << std::endl << std::endl;
}

void Harl::_info() {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "<someInfoText>." << std::endl << std::endl;
}
void Harl::_warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "<someWarningText>." << std::endl << std::endl;
}

void Harl::_error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "<someErrorText>." << std::endl << std::endl;
}
