#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <sstream>

class Harl {
	public:
		// Enum
		enum Level {
			DEBUT,
			INFO,
			WARNING,
			ERROR
		};

		// Constructor
		Harl();
		// Destructor
		~Harl();
		// Member Functions
		void complain(std::string level);


	private:
		void _debut();
		void _info();
		void _warning();
		void _error();

		void (Harl::*complain_ptr[4])() = {&Harl::_debut, &Harl::_info, &Harl::_warning, &Harl::_error};
};

#endif
