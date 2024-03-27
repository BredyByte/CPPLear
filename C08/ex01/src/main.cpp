#include "Span.hpp"

int main() {
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span A;
    try {
        A.addNumber(12);
        A.addNumber(0);
        A.addNumber(8);
    }
    catch (std::exception &e) {
        std::cout << "A: " << e.what() << std::endl;
    }
    try {
        std::cout << "A shortest: " << A.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }


    Span B(5);
    try {
        B.addNumber(98);
        B.addNumber(0);
        B.addNumber(17);
        B.addNumber(9);
        B.addNumber(-1);
        std::cout << "B shortest: " << B.shortestSpan() << std::endl;
        std::cout << "B longest: " << B.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Span C(1);
    try {
        C.addNumber(1231);
        std::cout << "C longest: " << C.longestSpan() << std::endl;
        std::cout << "C shortest: " << C.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    const size_t vectoreSize = 50000;
    std::vector<int> numbers(vectoreSize);
    for (size_t i = 0; i < vectoreSize; i++) {
        numbers[i] = i;
    }

    Span D(10000);
    try {
        D.fillRange(numbers.begin(), numbers.end());
    }
    catch (std::exception &e) {
        std::cout << "D: " << e.what() << std::endl;
    }

    Span E(vectoreSize);
    try {
        E.fillRange(numbers.begin(), numbers.end());
        std::cout << "E shortest: " << E.shortestSpan() << std::endl;
        std::cout << "E longest: " << E.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
