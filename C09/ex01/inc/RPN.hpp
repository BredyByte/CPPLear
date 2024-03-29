#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <fstream>
#include <sstream>
#include <exception>

class RPN {
public:
	RPN(RPN const& other);
	RPN(std::string const& str);
	~RPN();
	RPN& operator=(RPN const& other);
	void initCalc();
private:
	std::queue<int> _numbers;
	std::queue<std::string> _signs;
	int _res;
	RPN();
};

#endif
