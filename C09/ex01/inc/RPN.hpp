#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>
#include <exception>

class RPN {
public:
	RPN(RPN const& other);
	RPN(std::string const& str);
	~RPN();
	RPN& operator=(RPN const& other);
private:
	std::stack<float> _numbers;
	float _res;
	RPN();
};

#endif
