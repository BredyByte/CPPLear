#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(PmergeMe const& other) {
	*this = other;
};

PmergeMe& PmergeMe::operator=(PmergeMe const& other) {
	if (this != &other) {
		_list = other._list;
		_vector = other._vector;
	}
	return *this;
};

std::list<int> PmergeMe::getList() const {
	return _list;
}

std::vector<int> PmergeMe::getVector() const {
	return _vector;
}

PmergeMe::PmergeMe(char ** const argv, int argc, std::string const flag) {
	char **aux = argv;
	aux++;
	for (int i = 0; i < argc; ++i) {
		int x = 0;
		if (std::sscanf(aux[i], "%d", &x) == 1 && x >= 0) {
			if (flag == "LIST") {
				_list.push_back(x);
			}
			else if (flag == "VECTOR") {
				_vector.push_back(x);
			}
			else {
				throw std::runtime_error("Error: Bad constructor arguments");
			}
		}
		else {
			throw std::runtime_error("Error: Can't parse it, bad arguments");
		}
	}
};

void PmergeMe::sortVect() {
	//std::cout << "Before: " << _vector << std::endl;
	//std::cout << "After: " << _vector << std::endl;
}

void PmergeMe::sortList() {
	//std::cout << "Before: " <<_list << std::endl;
	//std::cout << "After: " <<_list << std::endl;
}

std::ostream& operator<<(std::ostream& os, const PmergeMe& obj) {
    std::list<int> list = obj.getList();
	if (!list.empty()) {
		os << "List: [ ";
		for (std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it) {
			os << *it << " ";
		}
		os << "]";
	}

    std::vector<int> vec = obj.getVector();
    if (!vec.empty()) {
		os << "Vector: [ ";
		for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
			os << *it << " ";
		}
		os << "]";
	}

    return os;
}
