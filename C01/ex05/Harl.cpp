#include "Harl.hpp"

Harl::Harl() {

}

Harl::~Harl() {

}

int stringToInt(const std::string& str) {
    std::stringstream s(str);
	int result;

	s >> result;

    if (s.fail() || !s.eof()) {
		std::cerr << "Error: Conversion failed. Value of level: " << str << std::endl;
		return (-1);
	}

    return (result);
}

void Harl::complain(std::string level) {
	int levelInt = stringToInt(level);

	switch (levelInt) {
		case DEBUT:
			_debut();
			break;
		case INFO:
			_info();
			break;
		case WARNING:
			_warning();
			break;
		case ERROR:
			_error();
			break;
		default:
		    std::cerr << "Error: Unknown log level." << std::endl;
			break;
	}
}

void Harl::_debut() {
	std::cout << "Debut: <someDebutText>." << std::endl;
}

void Harl::_info() {
	std::cout << "Info: <someInfoText>." << std::endl;
}
void Harl::_warning() {
	std::cout << "Warning: <someWarningText>." << std::endl;
}

void Harl::_error() {
	std::cout << "Error: <someErrorText>." << std::endl;
}
