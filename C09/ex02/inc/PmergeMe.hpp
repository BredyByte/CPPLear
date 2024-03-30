#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <ctime>
#include <vector>
#include <cstdio>
#include <list>

class PmergeMe {
private:
	PmergeMe();
	std::list<int> _list;
	std::vector<int> _vector;
public:
	~PmergeMe();
	PmergeMe(PmergeMe const& other);
	PmergeMe(char **const argv, int argc, std::string const flag);
	PmergeMe& operator=(PmergeMe const& other);
	void sortList();
	void sortVect();
	std::list<int> getList() const;
	std::vector<int> getVector() const;
};

std::ostream& operator<<(std::ostream& os, const PmergeMe& obj);

#endif
