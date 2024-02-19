#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default target") {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()) {
    this->_target = other.getTarget();
    this->isSignedSetter(other.formIsSigned());
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other) {
    this->_target = other.getTarget();
    this->isSignedSetter(other.formIsSigned());
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

std::string ShrubberyCreationForm::getTarget() const {
    return _target;
}

std::string printTreeASCII() {
    std::string treeASCII =
        "            .        +          .      .          .\n"
        "     .            _        .                    .\n"
        "  ,              /;-._,-.____        ,-----.__\n"
        " ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n"
        "  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n"
        "                      ,    `./  \\:. `.   )==-'  .\n"
        "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n"
        ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n"
        "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n"
        "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n"
        "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n"
        "              \\:  `  X` _| _,\\/\\'   .-'\n"
        ".               \":._:`\\____  /:'  /      .           .\n"
        "                    \\::.  :\\/:'  /              +\n"
        "   .                 `.:.  /:'  }      .\n"
        "           .           ):_(:;   \\           .\n"
        "                      /:. _/ ,  |\n"
        "                   . (|::.     ,`                  .\n"
        "     .                |::.    \\{\\\n"
        "                      |:::\\\\  \\ `.\n"
        "                      |:::(\\    |\n"
        "              O       |:::/{ }  |                  (o\n"
        "               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n"
        "          ~~~w/w~\"~~,\\\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n"
        "dew   ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~)";
    return treeASCII;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	(void) executor;
	const std::string fileName = this->_target + "_shrubbery";
    std::ofstream outputFile(fileName);

	if (outputFile.is_open()) {
		outputFile << printTreeASCII() << std::endl;
		outputFile.close();
		std::cout << "\nFile '" << fileName << "' created successfully.\n" << std::endl;
	} else {
		std::cerr << "\nError: Unable to create file '" << fileName << "'.\n" << std::endl;
	}
}
