#include "iostream"

void ToUpperString(char **str) {
	for (int i = 0; str[i]; i++) {
		std::string Frase = str[i];
		for (std::string::iterator it = Frase.begin(); it != Frase.end(); it++) {
			std::cout << (char)toupper(*it);
		}
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else {
		ToUpperString(argv+1);
	}
	return (0);
}
