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

template <typename Container>
Container merge(Container const& left, Container const& right) {
    Container merged;
    typename Container::const_iterator it_left = left.begin();
    typename Container::const_iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end()) {
        if (*it_left <= *it_right) {
            merged.push_back(*it_left);
            ++it_left;
        } else {
            merged.push_back(*it_right);
            ++it_right;
        }
    }

    while (it_left != left.end()) {
        merged.push_back(*it_left);
        ++it_left;
    }
    while (it_right != right.end()) {
        merged.push_back(*it_right);
        ++it_right;
    }

    return merged;
}

template <typename Container>
Container mergeSort(Container const& container) {
    Container sorted(container);
    typename Container::iterator begin = sorted.begin();
    typename Container::iterator end = sorted.end();
    size_t len = std::distance(begin, end);

    if (len <= 1) {
        return sorted;
    }

    Container left;
    size_t half = len / 2;
    size_t i = 0;
    typename Container::iterator it = begin;
    while (i < half) {
        left.push_back(*it);
        ++it;
        ++i;
    }

    Container right;
    while (it != end) {
        right.push_back(*it);
        ++it;
    }

    left = mergeSort(left);
    right = mergeSort(right);

	return merge(left, right);
}

void PmergeMe::sortVect() {
	if (!_vector.empty()) {
		_vector = mergeSort(_vector);
	} else {
		throw std::runtime_error("Error Can't sort: vector is empty");
	}
}

void PmergeMe::sortList() {
	if (!_list.empty()) {
		_list = mergeSort(_list);
	} else {
		throw std::runtime_error("Error Can't sort: list is empty");
	}
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
